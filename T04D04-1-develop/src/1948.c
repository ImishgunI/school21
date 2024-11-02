#include <stdio.h>
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        int q = n;
        int c = 0;

        while (q >= i) {
            q -= i;
            c++;
        }

        if (q == 0) {
            return 0;
        }
    }
    return 1;
}

int largest_prime_divisor(int n) {
    if (n < 0) {
        n = -n;
    }

    if (n < 2) {
        return -1;
    }

    int largest_prime = -1;

    for (int i = 2; i <= n; i++) {
        int q = n;
        int c = 0;

        while (q >= i) {
            q -= i;
            c++;
        }

        if (q == 0 && is_prime(i)) {
            largest_prime = i;
        }
    }

    return largest_prime;
}

int main() {
    int a;

    if (scanf("%d", &a) != 1) {
        printf("n/a");
        return 1;
    }

    int result = largest_prime_divisor(a);

    if (result == -1) {
        printf("n/a");
    } else {
        printf("%d", result);
    }

    return 0;
}
