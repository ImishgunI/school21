#include <stdio.h>

int sum(int a, int b);
int subtraction(int a, int b);
int multiply(int a, int b);
int division(int a, int b);


int main()
{
    int x,y;
    if(scanf("%d", &x) == 1 && scanf("%d", &y) == 1){
        printf("%d %d %d ", sum(x, y), subtraction(x, y), multiply(x, y));
        if(y == 0){
           printf("n/a");
        }else {
           printf("%d",division(x, y));
        }
    }else {
        printf("n/a");
    }
    return 0;
}

int sum(int a, int b){
    return a + b;
}

int subtraction(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int division(int a, int b){
    return a / b;
}
