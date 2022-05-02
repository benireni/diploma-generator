/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Sistema de Gerenciamento de Músicas
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_STR_SIZE 11
#define PLAYLISY_MAX_LEN 15

enum commands {
    ADD  = 1,
    SHOW = 2,
    NEXT = 3,
    PREV = 4,
    HALT = 5
};

typedef struct {
    char *name, *artist;
    unsigned int secLength;
} Song;

char *readLine();

int main() {
    
    Song playlistSongs[PLAYLISY_MAX_LEN];
    unsigned int playlistLength = 0, currentSongIndex = 0;
    char *playlistName = readLine();

    unsigned int command;
    scanf("%u ", &command);
    while (command != HALT) {

        if (command == ADD && playlistLength < PLAYLISY_MAX_LEN) {

            Song newSong;
            newSong.name = readLine();
            newSong.artist = readLine();
            scanf("%u ", &newSong.secLength);

            playlistSongs[playlistLength] = newSong;
            playlistLength++;

            printf("Musica %s de %s adicionada com sucesso.\n", newSong.name, newSong.artist);

        } else if (command == ADD) printf("Playlist cheia!\n");

        else if (command == SHOW) {
            printf("---- Playlist: %s ----\n", playlistName);
            printf("Total de musicas: %u\n\n", playlistLength);

            for (int songIndex = 0; songIndex < playlistLength; songIndex++) {
                if (songIndex == currentSongIndex) printf("=== NOW PLAYING ===\n");
                printf("(%u). '%s'\n", songIndex + 1, playlistSongs[songIndex].name);
                printf("Artista: %s\n", playlistSongs[songIndex].artist);
                printf("Duracao: %u segundos\n\n", playlistSongs[songIndex].secLength);
            }
        }

        else if (command == NEXT)
            currentSongIndex = (currentSongIndex != playlistLength - 1)
                ? currentSongIndex + 1 : 0;

        else if (command == PREV)
            currentSongIndex = (currentSongIndex != 0)
                ? currentSongIndex - 1 : playlistLength - 1;

        else if (command == HALT)
            break;

        scanf("%u ", &command);
    }

    free(playlistName);
    for (int i = 0; i < playlistLength; i++) {
        free(playlistSongs[i].name);
        free(playlistSongs[i].artist);
    }

    return 0;
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