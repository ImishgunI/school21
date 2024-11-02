#include "print_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t mytime = time(NULL);
    struct tm* now = localtime(&mytime);
    char* str = Log_prefix;
    for(int i = 0; str[i] != '\0'; ++i) {
        print(str[i]);
    }
    char time[20];
    strftime(time, sizeof(time), "%T", now); // функция форматирования для времени и заполнений его в массив
    printf(" %s %s", time, message);
}

