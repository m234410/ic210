/* pairs.c: Read in x and y values and pair them up.
 * Erase this comment and put your name here!
 * Your actual code should start below.
 Daniel Murray 234410*/

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int main(){
  printf("N: ");
  int N = 0;
  scanf(" %d", &N);
  double xvalues[N];
  double yvalues[N]; 

  printf("x values: ");
  for(int i = 0; i < N; ++i){
    scanf(" %lg", &xvalues[i]);
  }
  
  printf("y values: ");
  for(int i = 0; i < N; ++i){
    scanf(" %lg", &yvalues[i]);
  }
  
  for(int i = 0; i < N; ++i){
    printf("(%g,%g) ", xvalues[i], yvalues[i]);
  }
  
  printf("\n");

  return 0;

}
