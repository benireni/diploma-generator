/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Playlist Management System
 *******************************************************************************

TUTS TUTS TUTS TUTS TUTS TUTS QUERO VE
###########################################################################
########################XX///X#############################################
#######################XX///////X##########################################
#####################"#P"""""""Y#"#########################################
####################( #"^##P"##.# )########################################
#####################.#b.  .b .d#.#########################################
#######################"b.---.d##.:%0######################################
#####################"  `#m.m#'....::%0####################################
##################P"  .. |"""|   ....::%0##################################
##############P"" . .... `. ,'      ..:.::%0###############################
#############.  . ....::  |.|         ....:::%0############################
#############b .. .:.:::  |.|  . .:.     ...::::%0#########################
##########"  `#:.::::::   .|  . :.:%%%..   ....::::%0######################
########"" .md##::::%#:: :.| ....:.::%%#o.  ....:.:::%0####################
########mm#######::%##%. ..| ..:.:.::%%###o.  .....::::####################
#####P""    ""^Y#######m.. |  . :.:.%:%#####o.  ..mm^^0####################
###(     "^"     )##########mm.. :.:.:%#######o..#P     `^#################
#####mmm.....mmm################################## m  m . )################
##################################################m##.m.b.#################
#mm...""^^##################################0P""""          """^Y##########
########mmmm...""^^########################(         "^"         )#########
#################mmmm....""^^###############0mmm...       ...mmm0##########
###########################mmmm....""""^^##################################
######################################mmmmm.....""""#######################
'########################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 4
#define PLAYLISY_MAX_LEN 15

enum commands {
    ADD  = 1,
    SHOW = 2,
    NEXT = 3,
    PREV = 4,
    SAVE = 5,
    LOAD = 6,
    HALT = 7
};

typedef struct {
    char *name;
    char *artist;
    unsigned int duration;
} Song;

typedef struct {
    char *name;    
    int length, size, cursor;
    Song *songs;
} Playlist;

char *readLine();
void binaryToNum(char *binFileName);

Playlist loadPlaylist(char *fileName);
void savePlaylist(Playlist *playlist, char *fileName);
void freePlaylist(Playlist *playlist);


int main(int argc, char const *argv[]) {

    Playlist currentPlaylist = {
        .name = readLine(),
        .songs = malloc(sizeof(Song) * INITIAL_SIZE),
        .size = INITIAL_SIZE,
        .cursor = 0,
        .length = 0
    };

    unsigned int command;
    scanf("%u ", &command);
    while (command != HALT) {

        if (command == ADD && currentPlaylist.length < PLAYLISY_MAX_LEN) {
            Song newSong;
            newSong.name = readLine();
            newSong.artist = readLine();
            scanf("%u ", &newSong.duration);

            if (currentPlaylist.length == currentPlaylist.size) {
                currentPlaylist.size *= 2;
                currentPlaylist.songs = realloc(currentPlaylist.songs, sizeof(Song) * currentPlaylist.size);
            }

            currentPlaylist.songs[currentPlaylist.length] = newSong;
            currentPlaylist.length++;

            printf("Musica %s de %s adicionada com sucesso.\n", newSong.name, newSong.artist);

        } else if (command == ADD) {
            printf("Playlist cheia!\n");
        }

        else if (command == SHOW) {
            printf("---- Playlist: %s ----\n", currentPlaylist.name);
            printf("Total de musicas: %u\n\n", currentPlaylist.length);

            for (int songIndex = 0; songIndex < currentPlaylist.length; songIndex++) {
                if (songIndex == currentPlaylist.cursor) printf("=== NOW PLAYING ===\n");
                printf("(%u). '%s'\n", songIndex + 1, currentPlaylist.songs[songIndex].name);
                printf("Artista: %s\n", currentPlaylist.songs[songIndex].artist);
                printf("Duracao: %u segundos\n\n", currentPlaylist.songs[songIndex].duration);
            }
        }

        else if (command == NEXT) {
            currentPlaylist.cursor = (currentPlaylist.cursor != currentPlaylist.length - 1)
                ? currentPlaylist.cursor + 1 : 0;
        }

        else if (command == PREV) {
            currentPlaylist.cursor = (currentPlaylist.cursor != 0)
                ? currentPlaylist.cursor - 1 : currentPlaylist.length - 1;
        }

        else if (command == SAVE) {
            char *fileName = readLine();
            
            savePlaylist(&currentPlaylist, fileName);
            printf("Playlist %s salva com sucesso.\n", fileName);
            binaryToNum(fileName);
            free(fileName);
        }

        else if (command == LOAD) {
            char *fileName = readLine();
            freePlaylist(&currentPlaylist);

            currentPlaylist = loadPlaylist(fileName);
            printf("Playlist %s carregada com sucesso.\n", fileName);
            binaryToNum(fileName);
            free(fileName);
        }

        scanf("%u ", &command);
    }

    freePlaylist(&currentPlaylist);
    return 0;
}

void savePlaylist(Playlist *playlist, char *fileName) {
    FILE *playlistRecord = fopen(fileName, "wb");

    if (playlistRecord == NULL) {
        printf("Arquivo %s nao existe.\n", fileName);
        freePlaylist(playlist);
        free(fileName);
        exit(1);
    }

    // binary file header model: playlistNameLength(int) playlistName(str) playlistLength(int)
    int playlistNameLen = strlen(playlist->name);
    fwrite(&playlistNameLen, sizeof(int), 1, playlistRecord);
    fwrite(playlist->name, sizeof(char), playlistNameLen, playlistRecord);
    fwrite(&playlist->length, sizeof(int), 1, playlistRecord);

    playlist->songs = realloc(playlist->songs, sizeof(Song) * playlist->length);
    for (int i = 0; i < playlist->length; i++) {
        Song currentSong = playlist->songs[i];

        int songNameLen = strlen(currentSong.name);
        fwrite(&songNameLen, sizeof(int), 1, playlistRecord);
        fwrite(currentSong.name, sizeof(char), songNameLen, playlistRecord);

        int artistNameLen = strlen(currentSong.artist);
        fwrite(&artistNameLen, sizeof(int), 1, playlistRecord);
        fwrite(currentSong.artist, sizeof(char), artistNameLen, playlistRecord);

        fwrite(&currentSong.duration, sizeof(int), 1, playlistRecord);
    }

    fclose(playlistRecord);
}

Playlist loadPlaylist(char *fileName) {
    FILE *playlistRecord = fopen(fileName, "rb");
    if (playlistRecord == NULL) {
        printf("Arquivo %s nao existe.\n", fileName);
        free(fileName);
        exit(1);
    }

    // binary file header model: playlistNameLength(int) playlistName(str) playlistLength(int)
    Playlist playlist = { .cursor = 0 };

    int playlistNameLen;
    fread(&playlistNameLen, sizeof(int), 1, playlistRecord);
    playlist.name = malloc(sizeof(char) * (playlistNameLen + 1));

    fread(playlist.name, sizeof(char), playlistNameLen, playlistRecord);
    playlist.name[playlistNameLen] = '\0';

    fread(&playlist.length, sizeof(int), 1, playlistRecord);

    playlist.size = playlist.length;
    playlist.songs = malloc(sizeof(Song) * playlist.size);

    // binary file records model: songNameLen(int) songName(str) artistNameLen(int) artistName(str) songDuration(int)
    Song currentSong;
    int songNameLen, artistNameLen;
    for (int i = 0; i < playlist.length; i++) {
        fread(&songNameLen, sizeof(int), 1, playlistRecord);
        currentSong.name = malloc(sizeof(char) * (songNameLen + 1));

        fread(currentSong.name, sizeof(char), songNameLen, playlistRecord);
        currentSong.name[songNameLen] = '\0';

        fread(&artistNameLen, sizeof(int), 1, playlistRecord);
        currentSong.artist = malloc(sizeof(char) * (artistNameLen + 1));

        fread(currentSong.artist, sizeof(char), artistNameLen, playlistRecord);
        currentSong.artist[artistNameLen] = '\0';

        fread(&currentSong.duration, sizeof(int), 1, playlistRecord);

        playlist.songs[i] = currentSong;
    }

    fclose(playlistRecord);
    return playlist;
}

void freePlaylist(Playlist *playlist) {
    for (int i = 0; i < playlist->length; i++) {
        free(playlist->songs[i].name);
        free(playlist->songs[i].artist);
    }
    free(playlist->songs);

    free(playlist->name);
}

char *readLine() {

    int allocatedBytes = INITIAL_SIZE, currentLength = 0;
    char *line = malloc(allocatedBytes*sizeof(char)); // allocates with initial len

    do {

        // if at any point there is no available alocated memory left, double it
        if (currentLength == allocatedBytes) {
            allocatedBytes *= 2;
            line = realloc(line, allocatedBytes*sizeof(char));
        }

        char c = getchar();
        line[currentLength] = c;

        currentLength++;

    } while (line[currentLength - 1] != '\n' && line[currentLength - 1] != EOF);

    if (currentLength == 1 && line[currentLength - 1] == EOF) {
        free(line);
        return NULL;
    }

    line[currentLength - 1] = '\0';
    line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem

    return line;
}

void binaryToNum(char *binFilename) {
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}