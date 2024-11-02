#include <stdio.h>
#include <stdlib.h>  // Для malloc и free
#include <assert.h>  // Для assert

#include "list.h"
#include "door_struct.h"

// Прототипы тестов
void test_add();
void test_remove();

int main() {
    // Вызов тестов
    test_add();
    test_remove();
    
    printf("All tests passed!\n");
    return 0;
}

// Тест на добавление двери в список
void test_add() {
    // Инициализируем дверь
    struct door* door1 = malloc(sizeof(struct door));  // Выделяем память
    assert(door1 != NULL);  // Убедимся, что память выделена
    door1->id = 1;
    door1->status = 0;

    // Тестируем функцию init или добавления двери
    struct node* root = init(door1);  // Предполагается, что init создает первый элемент списка
    assert(root != NULL);             // Проверка, что список был успешно инициализирован
    assert(root->newdoor == door1);   // Проверяем, что дверь была добавлена
    
    printf("test_add passed!\n");
    
    // Освобождаем память после теста
    free(door1);
    free(root);
}

// Тест на удаление двери из списка
void test_remove() {
    // Инициализируем дверь
    struct door* door1 = malloc(sizeof(struct door));  // Выделяем память
    assert(door1 != NULL);  // Убедимся, что память выделена
    door1->id = 1;
    door1->status = 0;

    // Инициализируем список с одной дверью
    struct node* root = init(door1);
    assert(root != NULL);   // Убедимся, что список был создан

    // Тестируем удаление
    struct node* result = remove_door(root, root);  // Удаляем единственную дверь
    assert(result == NULL);  // Проверяем, что список пуст после удаления

    printf("test_remove passed!\n");

    // Освобождаем память после теста
    free(door1);
    // root уже был удален в remove_door, если оно освобождает память
}
