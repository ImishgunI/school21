#ifndef CIPHER_H
#define CIPHER_H
#include <stdio.h>

void read(FILE* file, char* filename, char* buffer);
void write(FILE* file, char* filename, char* string);
void output(char* buffer, int len);
int len(char* buffer);
#endif