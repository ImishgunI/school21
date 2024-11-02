#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define MAX_TEXT_LEN 100

void format_text(char* text, int width) {
    int start = 0, len = s21_strlen(text);
    if (text[len - 1] == '\n') text[--len] = '\0';

    while (start < len) {
        int end = start + width;

        if (end > len) end = len;

        while (end > start && text[end] != ' ' && text[end] != '-') end--;

        if (end == start) end = start + width;

        if (text[end] == '-' && end < len) {
            putchar(text[end]);
            end++;
        }

        for (int i = start; i < end; i++) {
            putchar(text[i]);
        }

        if (end < len) putchar('\n');

        while (text[end] == ' ') end++;

        start = end;
    }
}

int main(int argc, char** argv) {
    char* flag = "";
    flag = argv[1];
    char text[MAX_TEXT_LEN + 1];
    int width;
    if (argc != 2) {
        printf("n/a");
        return 1;
    } else if (s21_strcmp(flag, "-w") == 0) {
        scanf("%d", &width);
        fgets(text, MAX_TEXT_LEN, stdin);
        format_text(text, width);
    }
    return 0;
}