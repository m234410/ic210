// Daniel Murray m234410//


#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
typedef char cstring[128];

int main(){
  int seed = 1;
  int rolldie();
  int throwdie();
  printf("Enter seed value: ");
  scanf(" %d", &seed);
  srand(seed);
  int ret = 7;

  while(ret>0){
    ret = throwdie();
  }

  return 0;
}


int rolldie(){
  int roll = 1 +rand()%8;
  while(roll>6){
  roll = 1 +rand()%8;
  }
  return roll;
}

int throwdie(){
  int rolldie(); 
  int dice1 = rolldie();
  int dice2 = rolldie();
  int sum = dice1 +dice2;
  if(sum == 2 || sum == 3 || sum == 12){
    printf("Player rolled %i + %i = %i House wins!\n", dice1, dice2, sum);
    sum = -1*sum;
    return sum;
    }
  else if(sum == 7 || sum == 11){
    printf("Player rolled %i + %i = %i Player wins!\n", dice1, dice2, sum);
    return 0;
  }
  else{
    printf("Player rolled %i + %i = %i roll again\n", dice1, dice2, sum);
    return sum;
  }
}
