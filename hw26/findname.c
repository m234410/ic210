/* Daniel Murray 234410*/

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>


int main(){
  printf("Enter 5 names: ");
  char** names = calloc(5, sizeof(char*));
  for(int i = 0; i < 5; ++i){
    names[i] = calloc(128, sizeof(char));
    scanf(" %s", names[i]);
  }

  char letter;
  printf("Enter letter: ");
  scanf(" %c", &letter);

  // need to search for a space and a letter 


 search(names, 5, letter);

  

  return 0;
}

int search(char** names, int size, char* letter){
  int i = 0;
  while(i < size && !(match(names[i], letter))){
    i++;
  }
  return i;
}

bool match(void* a, void* b){
  //does the first letter of this cstring have this letter 
  if(a[0]==' '){
    return(a[1]==b);
  }
  else{
    return(a[0]==b);
  }
}
