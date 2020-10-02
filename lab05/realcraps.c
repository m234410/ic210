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
  int throwdieagain();
  int endprompt();
  printf("Enter seed value: ");
  scanf(" %d", &seed);
  srand(seed);
  int win = 0;
  int game = 0;
  int play = 1;

  while(play==1){
    int ret1 = throwdie();
    if(ret1<=0)
      play = endprompt();
    while(ret1>0){
      int ret2 = throwdieagain();
      if(ret2==ret1){
        printf("Player wins!\n");
        ret1 = 0; 
      }
      else if(ret2==7){
        printf("House wins!\n");
        ret1 = -1;
      }
      else{
        printf("roll again\n");
      }
      if(ret1<=0)
      play = endprompt();
    }
    
    ++game;
    if(ret1==0)
      ++win;
  }

  printf("You won %i of %i games.\n", win, game); 

  return 0;
}


int rolldie(){
  int roll = 1 +rand()%8;
  while(roll>6){
  roll = 1 +rand()%8;
  }
  return roll;
}

int endprompt(){
  char response;
  printf("Play again? ");
  scanf(" %c", &response);
  if(response == 'n')
    return 0;
  else if(response == 'y')
    return 1;
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

int throwdieagain(){
  int rolldie(); 
  int dice1 = rolldie();
  int dice2 = rolldie();
  int sum = dice1 +dice2;
    printf("Player rolled %i + %i = %i ", dice1, dice2, sum);
    return sum;
  }

