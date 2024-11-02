#include <stdio.h>

int main(){
    double x, y;
    if(scanf("%lf", &x) == 1 && scanf("%lf", &y) == 1){
      double formula = (x * x) + (y * y);
      if(formula <= 25){
	 printf("GOTCHA");
      }else {
	 printf("MISS");
      }
    }else {
      printf("n/a");
    }
    return 0;
}
