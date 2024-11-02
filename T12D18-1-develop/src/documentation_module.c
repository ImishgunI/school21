#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list ap;
    va_start(ap, document_count);

    int* array = calloc(document_count, sizeof(int));
    char* s;
    for (int i = 0; i < document_count; ++i) {
        s = va_arg(ap, char*);
        if (validate(s)) {
            array[i] = 1;
        } else {
            array[i] = 0;
        }
    }
    va_end(ap);
    return array;
}
