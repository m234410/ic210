/*Daniel Murray 234410 reads in two names and prints out name and time of
 * winner*/

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char cstring[128];
typedef struct{
  cstring name; 
  double time;
} athlete;
void print_athlete(athlete contestant);

int main(){
  athlete one;  /*initializes two athletes*/
  athlete two;
  
  printf("Enter the names and times of two racers:\n");     /*prompts user to enter two athletes and times*/
  scanf(" %s %lg %s %lg", one.name, &one.time, two.name, &two.time);

  if(one.time < two.time){ /* prints out the fastest athlete, assuming there is no tie possible */
    print_athlete(one);
  }
  else{
    print_athlete(two);
  }
  
  return 0;
}

void print_athlete(athlete racer){
  printf("%s won with a time of %g minutes.\n", racer.name, racer.time); /* prints out statement with name and time 
                                                                            of winning racer */
}
