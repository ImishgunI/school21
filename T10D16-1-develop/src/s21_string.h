#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char* str);
int s21_strcmp(const char* src, const char* dest);
char* s21_strcpy(char* dest, const char* src);
char* s21_strcat(char* dest, const char* append);
char* s21_strchr(const char* str, int ch);
char* s21_strstr(const char* strB, const char* strA);
#endif
