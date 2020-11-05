/* Daniel Murray 234410*/

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

bool match(void* a, void* b);
int search(char** names, int size, char* letter);

int main(){
  printf("Enter 5 names: ");
  char** names = calloc(5, sizeof(char*));
  for(int i = 0; i < 5; ++i){
    names[i] = calloc(128, sizeof(char));
    scanf(" %s", names[i]);

  }

  char letter;
  printf("Letter: ");
  scanf(" %c", &letter);
 
  int name_index = search(names, 5, &letter);
  if(name_index < 5){
    printf("%s\n", names[name_index]);
  }
  else{
    printf("not found\n");
  }

  return 0;
}

//helper functions
int search(char** names, int size, char* letter){
  int i = 0;
  while(i < size && !(match(names[i], letter))){
    i++;
  }
  return i;
}

bool match(void* a, void* b){
  int i = 0;
  char* name = a;
  char* letter = b;

  while(name[i]==' '){
      ++i;
  }
  return(name[i]==*letter);
}
