#ifndef STACK_H
#define STACK_H

// stack for operators
typedef struct stack {
    char* operand;
    struct stack* next;
} stack;

void push(stack** head, char* operand);
void pop(stack** node);
char* peek(stack* node);
int is_empty(stack* node);

// stack for numbers
typedef struct stack_number {
    double number;
    struct stack_number* next;
} stack_n;

void push_n(stack_n** head, double number);
stack_n* pop_n(stack_n** node);

#endif  // STACK_H
