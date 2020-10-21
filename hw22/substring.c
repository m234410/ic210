/* substring.c: Read two strings and determine whether one contains the other.
 * Erase this comment and put your name here!
 * Your actual code should start below.
 Daniel Murray 234410*/

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool is_substring(char* test, char* target);

int main(){
  char target[128] = {0};
  char test[128] = {0};
  printf("Target: ");
  scanf(" %s", target);
  printf("Test: ");
  scanf(" %s", test);
  if(is_substring(test, target))
    printf("yes\n");
  else
    printf("no\n");

  return 0;

}

bool is_substring(char* test, char* target){
  for(int i = 0; i < strlen(test); ++i){ 
    if(test[i] == target[0]){
      for(int j = 1; j < strlen(target); ++j){ 
        if(!(test[i+j] == target[j]))
          break;  
        else if(j == (strlen(target)-1))
          return true;
      }
    }
  }
  return false;
}
