#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "evaluator.h"
#include "lexer.h"
#include "stack.h"

int main() {
    char* expr = malloc(256 * sizeof(char));
    scanf("%s", expr);
    int len = strlen(expr);
    char* tokens = convert_to_rpn(expr, len);
    char* split_expr = split_rpn_expression(tokens);
    free(tokens);
    free(expr);
    double array[] = {-1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0,
                      0.1,  0.2,  0.3,  0.4,  0.5,  0.6,  0.7,  0.8,  0.9,  1.0};
    double values[21];
    stack_n* node = NULL;
    for (int i = 0; i < 21; ++i) {
        node = evaluate_rpn(split_expr, array);
        values[i] = node->number;
        free(node);
    }
    draw_graph(values, 21);
}