#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../stack.h"
#include "../lexer.h"
#include "../evaluator.h"

void push_test();
void pop_test();
void peek_test();
void rpn_test();
void evaluate_rpn_test();

int main() {
    printf("TEST PUSH\n");
    push_test();
    printf("\n\nTEST POP\n");
    pop_test();
    printf("\n\nTEST PEEK\n");
    peek_test();
    printf("\n\nTEST RPN\n");
    rpn_test();
    printf("\n\nTEST EVALUATE RPN\n");
    evaluate_rpn_test();
}

void push_test() {
    stack* node = NULL;
    push(&node, "sin");
    push(&node, "cos");
    push(&node, "+");

    printf("Head value: %s", node->operand);

}

void pop_test() {
    stack* node = NULL;
    push(&node, "sin");
    push(&node, "cos");
    push(&node, "+");

    printf("Before pop: %s\n", node->operand);
    pop(&node);
    printf("After pop: %s\n", node->operand);
}

void peek_test() {
    stack* node = NULL;
    push(&node, "sin");
    push(&node, "cos");
    push(&node, "+");

    printf("head value: %s\n", peek(node));
}

void rpn_test() {
    char* expr = "sin(x) * cos(2 * x)";
    int len = strlen(expr);
    char* tokens = NULL;
    char* split_expression = "";
    tokens = convert_to_rpn(expr ,len);
    split_expression = split_rpn_expression(tokens);
    free(tokens);
    printf("%s", split_expression);
    free(split_expression);
}

void evaluate_rpn_test() {
    char* expr = "sin(x) + cos(2 * x)";
    int len = strlen(expr);
    char* tokens = NULL;
    char* split_expression = "";
    tokens = convert_to_rpn(expr ,len);
    split_expression = split_rpn_expression(tokens);
    free(tokens);
    double array[] = {-1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0,
                      0.1,  0.2,  0.3,  0.4,  0.5,  0.6,  0.7,  0.8,  0.9,  1.0};
    double values[21];
    stack_n* node = NULL;
    for(int i = 0; i < 21; ++i) {
        node = evaluate_rpn(split_expression, array);
        values[i] = node->number;
        free(node);
    }
    for(int i = 0; i < 21; ++i) {
        printf("%lf ", values[i]);
    }
}