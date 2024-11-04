#include "evaluator.h"

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

stack_n* evaluate_rpn(char* rpn_string, double* values) {
    stack_n* node = NULL;
    int len = strlen(rpn_string);
    double n1 = 0, n2 = 0, res = 0;
    stack_n* delete_node = NULL;
    double x = 0.0;
    for (int i = 0; i < len; ++i) {
        if (isdigit(rpn_string[i])) {
            int number = rpn_string[i] - 48;
            while (isdigit(rpn_string[i++])) {
                number = number * 10 + rpn_string[i] - 48;
            }
            double res1 = (double)number;
            push_n(&node, res1);
            if (rpn_string[i] == 'x') {
                static int j = 0;
                x = values[j++];
                push_n(&node, x);
            }
        } else if (rpn_string[i] == '+' || rpn_string[i] == '-' || rpn_string[i] == '*' ||
                   rpn_string[i] == '/') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            free(delete_node);
            delete_node = pop_n(&node);
            n2 = delete_node->number;
            free(delete_node);
            if (rpn_string[i] == '+') {
                res = n1 + n2;
                push_n(&node, res);
            } else if (rpn_string[i] == '-') {
                res = n1 - n2;
                push_n(&node, res);
            } else if (rpn_string[i] == '*') {
                res = n1 * n2;
                push_n(&node, res);
            } else if (rpn_string[i] == '/') {
                res = n1 / n2;
                push_n(&node, res);
            }
        } else if (rpn_string[i] == 's' && rpn_string[i + 1] == 'i' && rpn_string[i + 2] == 'n') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            res = sin(n1);
            free(delete_node);
            push_n(&node, res);
        } else if (rpn_string[i] == 'c' && rpn_string[i + 1] == 'o' && rpn_string[i + 2] == 's') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            res = cos(n1);
            free(delete_node);
            push_n(&node, res);
        } else if (rpn_string[i] == 't' && rpn_string[i + 1] == 'a' && rpn_string[i + 2] == 'n') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            res = tan(n1);
            free(delete_node);
            push_n(&node, res);
        } else if (rpn_string[i] == 'c' && rpn_string[i + 1] == 't' && rpn_string[i + 2] == 'g') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            res = cos(n1) / sin(n1);
            free(delete_node);
            push_n(&node, res);
        } else if (rpn_string[i] == 's' && rpn_string[i + 1] == 'q' && rpn_string[i + 2] == 'r' &&
                   rpn_string[i + 3] == 't') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            res = sqrt(n1);
            free(delete_node);
            push_n(&node, res);
        } else if (rpn_string[i] == 'l' && rpn_string[i + 1] == 'n') {
            delete_node = pop_n(&node);
            n1 = delete_node->number;
            res = log(n1);
            free(delete_node);
            push_n(&node, res);
        }
    }
    delete_node = pop_n(&node);
    return delete_node;
}