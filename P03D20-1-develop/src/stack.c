#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
/*
    Модуль для работы со стеком (stack):
        Задача: Организует динамическую структуру данных для работы с алгоритмом сортировочной станции и
   вычислением выражений. Вход: Лексемы. Выход: Сохранение состояния операций и значений.

    Функции:
        push(), pop(): Операции для работы со стеком.
        peek(): Просмотр верхнего элемента стека без удаления.
*/

void push(stack** head, char* operand) {
    stack* node = malloc(sizeof(stack));
    if (node == NULL) {
        perror("memory wasn't been allocated\n");
        return;
    }

    node->operand = operand;
    node->next = *head;
    *head = node;
}

void pop(stack** node) {
    stack* delete_node;
    if (*node == NULL) {
        perror("stack is empty");
        return;
    }
    delete_node = *node;
    *node = (*node)->next;
    free(delete_node);
}

char* peek(stack* node) { return node->operand; }

int is_empty(stack* node) { return (node == NULL) ? 1 : 0; }

void push_n(stack_n** head, double number) {
    stack_n* node = malloc(sizeof(stack_n));
    if (node == NULL) {
        perror("memory wasn't been allocated\n");
        return;
    }

    node->number = number;
    node->next = *head;
    *head = node;
}

stack_n* pop_n(stack_n** node) {
    stack_n* delete_node;
    if (*node == NULL) {
        perror("stack is empty");
        return NULL;
    }
    delete_node = *node;
    *node = (*node)->next;
    return delete_node;
}