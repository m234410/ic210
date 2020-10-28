//Daniel Murray 234410//

#include <stdio.h>
#include <stdlib.h>

char** readletter(FILE* fin);
void printletter(char** array);
void freearray(char** array);

int main() {
  FILE* fin = fopen("letters.txt", "r");
  
  char** A = readletter(fin);
  char** N = readletter(fin);
  char** V = readletter(fin);
  char** Y = readletter(fin);
  
  printletter(N);
  printletter(A);
  printletter(V);
  printletter(Y);
  
  freearray(N);
  freearray(A);
  freearray(V);
  freearray(Y);
  fclose(fin);

  return 0;
}
char** readletter(FILE* fin){
  char** array = calloc(4, sizeof(char*));
  for(int i = 0; i < 4; i++) {
    array[i] = calloc(7, sizeof(char));
  }
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      array[i][j] = fgetc(fin);
    }
    while(fgetc(fin) != '\n') { }
  }
  return array;
}

void printletter(char** array){
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      printf("%c", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void freearray(char** array){
  for (int i = 0; i < 4; i++) {
    free(array[i]);
  }
  free(array);
}

