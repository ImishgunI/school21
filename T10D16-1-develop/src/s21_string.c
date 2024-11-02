#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char* str) {
    size_t length = 0;

    while (*str++ != '\0') {
        length++;
    }
    return length;
}

int s21_strcmp(const char* src, const char* dest) {
    size_t len1 = s21_strlen(src);
    size_t len2 = s21_strlen(dest);
    int i = 0;
    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    } else if (len1 == len2) {
        while (i++ < (int)len1) {
            if (src[i] != dest[i]) {
                return -2;
            }
        }
    }
    return 0;
}

char* s21_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char* s21_strcat(char* dest, const char* append) {
    int i = 0;
    int len = s21_strlen(dest);
    while (append[i] != '\0') {
        dest[len] = append[i];
        ++i;
        ++len;
    }
    dest[len] = '\0';
    return dest;
}

char* s21_strchr(const char* str, int ch) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            return (char*)(str + i);
        }
        ++i;
    }
    if (str[i] == '\0') {
        return (char*)str + i;
    }
    return NULL;
}

char* s21_strstr(const char* strB, const char* strA) {
    const char* a;
    const char* b;

    b = strB;

    if (*b == 0) {
        return (char*)strA;
    }

    for (; *strA != 0; strA++) {
        if (*strA != *b) {
            continue;
        }

        a = strA;
        while (1) {
            if (*b == 0) {
                return (char*)strA;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = strB;
    }
    return NULL;
}
