/*Daniel Murray*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
  printf("How many days? ");
  double days;
  scanf(" %lg", &days);
  
  double* alltemps = calloc(days, sizeof(double));
  double totaltemp = 0;
  int hotterdays = 0;
  
  printf("Enter temperatures\n");
  for(int i = 0; i < days; ++i){
    scanf(" %lg", &alltemps[i]);
    totaltemp += alltemps[i];
  }

  double averagetemp = totaltemp/days;

  for(int i = 0; i < days; ++i){
    if(alltemps[i] > averagetemp){
      ++hotterdays;
    }
  }

  printf("Average temperature: %g\n", averagetemp);
  printf("%i days were hotter than average\n", hotterdays);
  


  return 0;
}
