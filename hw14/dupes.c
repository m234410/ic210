// Daniel Murray//
// 234410//

#include<string.h>
#include<stdbool.h>
#include<stdio.h>
typedef char cstring[128];

int main(){
  int dupe(double a, double b, double c);
  double a, b, c = 0;
  int ret = 1;

    while(ret!=0){
      printf("Enter three distinct numbers: ");
      scanf(" %lg %lg %lg", &a, &b, &c);
      ret = dupe(a, b, c);
      if(ret!=0){
      printf("There were %i duplicates. Try again.\n", ret);
      dupe(a, b, c);
      }
    }
  return 0;
}
int dupe(double a, double b, double c){
  if(a==b&&b==c)
    return 3;
  else if(a==b||a==c||b==c)
    return 2;
  else
    return 0;
}

