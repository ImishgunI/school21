#include <stdio.h>

int max(int x, int y){
   if(x > y){
      return x;
   }else {
      return y;
   }
}


int main(){
  int x, y;
  if(scanf("%d", &x) == 1 && scanf("%d", &y) == 1){
    printf("%d", max(x, y));  
  }else {
    printf("n/a");
  }
  return 0;
}
