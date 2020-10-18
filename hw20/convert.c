/*Daniel Murray 234410*/

#include<string.h>
#include<stdio.h>
#include<stdbool.h>

int main(){
  char word[128];
  int conversions = 0; 
  char best_word[128] = "test";
  scanf(" %s", word);
  while(strcmp(word, "DONE")!=0){
    scanf(" %s", word);
    int counter = 0;
    for(int i = 0; i < strlen(word); ++i){
      if(word[i] == 'a'){
        word[i] = '@';
        ++counter;
      }
      else if(word[i] == 'e'){
        word[i] = '3';
        ++counter;
      }
      else if(word[i] =='i'){
        word[i] = '!';
        ++counter;
      }
      else if(word[i] == 't'){
        word[i] = '+';
        ++counter;
      }
      
      if(counter>conversions){
        conversions = counter;
        best_word[128] = word[128];
      }
    }

  }

  printf("%s", best_word);
  printf("%i", conversions);




  return 0;
}
