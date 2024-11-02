#include "cipher.h"

#include <stdio.h>

int main() {
    int numb = 0;
    char buffer[100];
    char filename[100];
    char string[100];
    FILE* file = NULL;
    int end = 1;
    while (end) {
        numb = 0;
        scanf("%d", &numb);
        while (getchar() != '\n')
            ;
        switch (numb) {
            case 1:
                scanf("%s", filename);
                read(file, filename, buffer);
                int size = len(buffer);
                output(buffer, size);
                break;
            case 2:
                fgets(string, 100, stdin);
                write(file, filename, string);
                read(file, filename, buffer);
                size = len(buffer);
                output(buffer, size);
                break;
            case -1:
                end = 0;
                break;
            default:
                printf("n/a\n");
                break;
        }
    }
}

void read(FILE* file, char* filename, char* buffer) {
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }
    int size = 0;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%c", &buffer[size]) != EOF) {
        ++size;
    }
    if (size == 0) {
        printf("n/a\n");
        fclose(file);
        return;
    }
    fclose(file);
}

void write(FILE* file, char* filename, char* string) {
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }
    int number = fputs(string, file);
    if (number < 0) {
        printf("n/a\n");
        return;
    }
    fclose(file);
}
void output(char* buffer, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%c", buffer[i]);
    }
}

int len(char* buffer) {
    int len = 0;
    while (buffer[len] != '\0') {
        ++len;
    }
    return len;
}