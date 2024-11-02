#include "logger.h"

#include <stdio.h>

#include "log_levels.h"

FILE* log_init(char* filename) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        return NULL;
    }
    return file;
}

int logcat(FILE* log_file, char* message, enum log_level level);

int log_close(FILE* log_file) {
    fclose(log_file);
    return 0;
}