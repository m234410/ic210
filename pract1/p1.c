//Daniel Murray//


#include<string.h>
#include<stdbool.h>
#include<stdio.h>
typedef char cstring[128];

int main(){
  double a = 0;
  double b = 0;
  cstring function; 
  char recipient = a; 
  printf("Values for a and b? ");
  scanf(" %lg, %lg", &a, &b);
  printf("What do you want? ");
  scanf(" %s", function);
  
  if(strcmp(function, "add")==0){
    double amount = 0;
    scanf(" %lg to %c", &amount, &recipient);
    if(recipient== 'a'){
        a = amount + a;
      }
      else if(recipient== 'b'){
        b = amount + b;
      }
  }

  else if(strcmp(function, "square")==0){
    scanf(" %c", &recipient);
      if(recipient== 'a'){
        a = a*a;
      }
      else if(recipient== 'b'){
        b = b*b;
      }
  }

  printf("a = %g and b = %g\n", a, b);
  
  return 0;
}
    

