//Daniel Murray 234410//

#include"countdown.h"
#include<stdio.h>

void countdown(int number){
  if(number>0){
    printf("%d\n", number);
    countdown(number-1);
  }
  else{
    printf("hooray!\n");
  }
}
