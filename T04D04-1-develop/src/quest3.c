#include <stdio.h>

long fibonacci(long a) {
    if (a == 1 || a == 2) {
        return 1;
    }
    if (a == 0) {
        return 0;
    }
    return fibonacci(a - 1) + fibonacci(a - 2);
}

int main() {
    long a;
    char c;
    scanf("%ld", &a);
    if ((c = getchar()) != '\n' || a < 0) {
        printf("n/a");
    } else {
        printf("%ld", fibonacci(a));
    }
}
