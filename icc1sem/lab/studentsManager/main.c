/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Jupiter.com
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 4
#define INITIAL_STR_SIZE 10

enum {
    GET_STUDENT_BY_ID      = '1',
    GET_STUDENTS_BY_COURSE = '2',
    GET_ALL_STUDENTS       = '3'
};

typedef struct {
    unsigned int age;
    char *name, *course, *uspId;
} Student;

typedef struct {
    Student *students;
    unsigned int length, size;
} UspDB;

char *readLine();
void printStudent(Student student);

Student consumeStudent();
Student *getStudentByUspId(char *uspId, UspDB db);
UspDB getCourseDB(char *course, UspDB db);

int main() {
    UspDB uspDB = {
        .students = malloc(INITIAL_SIZE * sizeof(Student)),
        .size = INITIAL_SIZE,
        .length = 0
    };

    char nextChar;
    while ((nextChar = fgetc(stdin)) != '-') {
        ungetc(nextChar, stdin);
        if (uspDB.length == uspDB.size) {
            uspDB.size *= 2;
            uspDB.students = realloc(
                uspDB.students,
                uspDB.size * sizeof(Student)
            );
        }
        uspDB.students[uspDB.length++] = consumeStudent();
    }

    uspDB.students = realloc(
        uspDB.students,
        uspDB.length * sizeof(Student)
    );

    fgetc(stdin); fgetc(stdin); // Consume '1' and '\n'
    while ((nextChar = fgetc(stdin)) != '-') {
        fgetc(stdin);
        switch (nextChar) {

        case GET_STUDENT_BY_ID: {
            char *uspId = readLine();
            Student *student = getStudentByUspId(uspId, uspDB);

            if (student == NULL) {
                printf("Aluno nao cadastrado\n");
                break;
            }

            printStudent(*student);
            free(uspId);
            break;
        }
        
        case GET_STUDENTS_BY_COURSE: {
            char *course = readLine();
            UspDB courseDB = getCourseDB(course, uspDB);

            for (int i = 0; i < courseDB.length; i++)
                printStudent(courseDB.students[i]);

            free(courseDB.students);
            free(course);
            break;
        }

        case GET_ALL_STUDENTS:
            for (int i = 0; i < uspDB.length; i++)
                printStudent(uspDB.students[i]);
            break;

        }

    }

    Student currentStudent;
    for (int i = 0; i < uspDB.length; i++) {
        currentStudent = uspDB.students[i];
        free(currentStudent.name);
        free(currentStudent.uspId);
        free(currentStudent.course);
    }

    free(uspDB.students);
    fflush(stdin);

    return 0;
}

void printStudent(Student student) {
    printf("Nome: %s\n", student.name);
    printf("Curso: %s\n", student.course);
    printf("N USP: %s\n", student.uspId);
    printf("IDADE: %d\n\n", student.age);
}

Student *getStudentByUspId(char *uspId, UspDB db) {
    for (int i = 0; i < db.length; i++) {
        if (strcmp(db.students[i].uspId, uspId) == 0)
            return &db.students[i];
    }
    return NULL;
}

UspDB getCourseDB(char *course, UspDB db) {

    UspDB courseDB = {
        .students = malloc(INITIAL_SIZE * sizeof(Student)),
        .size = INITIAL_SIZE,
        .length = 0
    };

    for (int i = 0; i < db.length; i++) {
        if (courseDB.length == courseDB.size) {
            courseDB.size *= 2;
            courseDB.students = realloc(
                courseDB.students,
                courseDB.size * sizeof(Student)
            );
        }

        if (strcmp(db.students[i].course, course) == 0)
            courseDB.students[courseDB.length++] = db.students[i];
    }

    return courseDB;
}

Student consumeStudent() {
    Student student;
    student.uspId = readLine();
    student.name = readLine();
    student.course = readLine();
    scanf(" %d", &student.age);
    fgetc(stdin);
    return student;
}

char *readLine() {

    int allocatedBytes = INITIAL_STR_SIZE, currentLength = 0;

    // allocates with initial len
    char *line = malloc(allocatedBytes*sizeof(char));

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

    // dismiss unused alocated mem
    line = realloc(line, sizeof(char) * currentLength);

    return line;
}