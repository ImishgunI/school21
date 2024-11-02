/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define SIZE 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);
int length(int *buffer, int length);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, a[SIZE], num[SIZE] = {0};
    if (input(a, &n) == 0) {
        printf("n/a");
    } else {
        int sum = sum_numbers(a, n);
        if (sum == 0) {
            printf("n/a");
        } else {
            printf("%d\n", sum);
            if (find_numbers(a, n, sum, num) == 1) {
                int size = length(num, n);
                output(num, size);
            } else {
                printf("n/a");
            }
        }
    }
}

int input(int *buffer, int *length) {
    scanf("%d", length);
    if (*length > SIZE) {
        return 0;
    }
    for (int *p = buffer; p - buffer < *length; ++p) {
        scanf("%d", p);
    }
    char c;
    if ((c = getchar()) != '\n') {
        return 0;
    } else {
        return 1;
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; ++i) {
        if (i < length - 1) {
            printf("%d ", buffer[i]);
        } else {
            printf("%d", buffer[i]);
        }
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    int count = 0;
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            count++;
        }
    }
    if (count > 0) {
        flag = sum;
    } else {
        flag = 0;
    }
    return flag;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    int flag = 0;
    for (int i = 0; i < length; ++i) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[count++] = buffer[i];
            }
        } else {
            continue;
        }
    }
    if (count > 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
}

int length(int *array, int n) {
    int length = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i] == 0) {
            continue;
        } else {
            length++;
        }
    }
    return length;
}