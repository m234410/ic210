// Daniel Murray m234410//


#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
typedef char cstring[128];

int main(){
  int seed = 1;
  int rolldie();
  printf("Enter seed value: ");
  scanf(" %d", &seed);
  srand(seed);

  for(int i = 1; i<=5; i++){
    int dice1 = rolldie();
    int dice2 = rolldie();
    int sum = dice1 + dice2; 
    printf("Player rolled %i + %i = %i\n", dice1, dice2, sum);
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

