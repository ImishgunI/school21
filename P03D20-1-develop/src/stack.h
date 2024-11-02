#ifndef STACK_H
#define STACK_H

typedef struct stack {
    char* operand;
    struct stack* next;
} stack;

void push(stack** head, char* operand);
void pop(stack** node);
char* peek(stack* node);
int is_empty(stack* node);
#endif  // STACK_H
