/*Daniel Murray 234410*/

#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
typedef char cstring[128];

int main(){
  int size = 1;
  double* array = calloc(size,sizeof(double));
  cstring indicator;
  for(int i = 0; scanf(" %lg", &array[i]) == 1; ++i){
    if(i==(size-1)){
      ++size;
      array = realloc(array, size*sizeof(double));
    }
  }

  scanf(" %s", indicator);
  if(strcmp(indicator, "below")==0){
    for(int i = 0; i < (size - 1); ++i){
      if(array[i]<0)
        printf("%g\n", array[i]);
    }
  }
  else if(strcmp(indicator, "above")==0){
    for(int i = 0; i < (size - 1); ++i){
      if(array[i]>0)
        printf("%g\n", array[i]);
    }
  }

  return 0;
}
