// Daniel Murray m234410//


#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
typedef char cstring[128];

int main(){
  int seed = 1;
  printf("Seed me: ");
  scanf(" %d", &seed);
  int realcraps(int seed);
  printf("%i seed gives %i wins\n", seed, realcraps(seed));

  return 0;
}









int realcraps(int seed){
  int rolldie();
  int throwdie();
  int throwdieagain();
  srand(seed);
  int win = 0;

  while(true){
    int ret1 = throwdie();
    if(ret1<0)
      break;
    while(ret1>0){
      int ret2 = throwdieagain();
      if(ret2==ret1){
        ret1 = 0; 
      }
      else if(ret2==7){
        return(win);
      }
      else{
      }
    }
    
    if(ret1==0)
      ++win;
  }
 

  return win;
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
    sum = -1*sum;
    return sum;
    }
  else if(sum == 7 || sum == 11){
    return 0;
  }
  else{
    return sum;
  }
}

int throwdieagain(){
  int rolldie(); 
  int dice1 = rolldie();
  int dice2 = rolldie();
  int sum = dice1 +dice2;
    return sum;
  }
