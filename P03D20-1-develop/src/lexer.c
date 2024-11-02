#include "lexer.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int preoritet(char* operator) {
    if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0) return 1;
    if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0) return 2;
    if (strcmp(operator, "(") == 0 || strcmp(operator, ")") == 0) return 4;
    return 3;
}
char* to_string(char operator, char * str) {
    str = malloc(2 * sizeof(char));
    str[0] = operator;
    str[1] = '\0';
    return str;
}

int is_variable(char* x) { return (strcmp(x, "x") == 0) ? 1 : 0; }

char* convert_to_rpn(char* expression, int length) {
    char* tokens = malloc(256 * sizeof(char));
    stack* operators = NULL;
    for (int i = 0; i < length; ++i) {
        char c = expression[i];
        char* str = to_string(c, str);
        if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 ||
            strcmp(str, "/") == 0) {
            if (is_empty(operators) == 0) {
                if (preoritet(str) == 1 &&
                    (preoritet(operators->operand) == 3 || preoritet(operators->operand) == 2 ||
                     preoritet(operators->operand) == 1)) {
                    strcat(tokens, peek(operators));
                    pop(&operators);
                    push(&operators, str);
                } else if (preoritet(str) == 2 &&
                           (preoritet(operators->operand) == 3 || preoritet(operators->operand) == 2)) {
                    strcat(tokens, peek(operators));
                    pop(&operators);
                    push(&operators, str);
                } else {
                    push(&operators, str);
                }
            } else {
                push(&operators, str);
            }
        } else if (expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n') {
            push(&operators, "sin");
        } else if (expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's') {
            push(&operators, "cos");
        } else if (expression[i] == 't' && expression[i + 1] == 'a' && expression[i + 2] == 'n') {
            push(&operators, "tan");
        } else if (expression[i] == 'c' && expression[i + 1] == 't' && expression[i + 2] == 'g') {
            push(&operators, "ctg");
        } else if (expression[i] == 's' && expression[i + 1] == 'q' && expression[i + 2] == 'r' &&
                   expression[i + 3] == 't') {
            push(&operators, "sqrt");
        } else if (expression[i] == 'l' && expression[i + 1] == 'n') {
            push(&operators, "ln");
        } else if (strcmp(str, "(") == 0) {
            push(&operators, str);
        } else if (strcmp(str, ")") == 0) {
            while (strcmp(operators->operand, "(") != 0) {
                strcat(tokens, peek(operators));
                pop(&operators);
            }
            pop(&operators);
        }
        if (is_variable(str)) {
            strcat(tokens, str);
        } else if (c >= 48 && c <= 57) {
            strcat(tokens, str);
        }
        if (i + 1 == length) {
            free(str);
            break;
        }
    }
    while (operators != NULL) {
        strcat(tokens, peek(operators));
        pop(&operators);
    }
    return tokens;
}

char* split_rpn_expression(char* tokens) {
    int len = strlen(tokens);
    char* split_expression = malloc(len * 2 + 1);
    if (split_expression == NULL) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (isdigit(tokens[i])) {
            while (isdigit(tokens[i])) {
                split_expression[j++] = tokens[i++];
            }
            split_expression[j++] = ' ';
            i--;
        } else if (tokens[i] == 's' && tokens[i + 1] == 'i' && tokens[i + 2] == 'n') {
            memcpy(&split_expression[j], "sin ", 4);
            j += 4;
            i += 2;
        } else if (tokens[i] == 'c' && tokens[i + 1] == 'o' && tokens[i + 2] == 's') {
            memcpy(&split_expression[j], "cos ", 4);
            j += 4;
            i += 2;
        } else if (tokens[i] == 't' && tokens[i + 1] == 'a' && tokens[i + 2] == 'n') {
            memcpy(&split_expression[j], "tan ", 4);
            j += 4;
            i += 2;
        } else if (tokens[i] == 'c' && tokens[i + 1] == 't' && tokens[i + 2] == 'g') {
            memcpy(&split_expression[j], "ctg ", 4);
            j += 4;
            i += 2;
        } else if (tokens[i] == 's' && tokens[i + 1] == 'q' && tokens[i + 2] == 'r' && tokens[i + 3] == 't') {
            memcpy(&split_expression[j], "sqrt ", 5);
            j += 5;
            i += 3;
        } else if (tokens[i] == 'l' && tokens[i + 1] == 'n') {
            memcpy(&split_expression[j], "ln ", 3);
            j += 3;
            i += 1;
        } else {
            split_expression[j++] = tokens[i];
            split_expression[j++] = ' ';
        }
    }
    split_expression[j] = '\0';
    return split_expression;
}