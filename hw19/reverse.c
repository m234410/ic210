/*Daniel Murray 234410*/

#include<string.h>
#include<stdbool.h>
#include<stdio.h>

int main(){
  int rows = 0;
  printf("How many numbers? ");
  scanf(" %d", &rows);
  int array[rows];
  printf("Enter %i numbers: ", rows);

  for(int i = 0; i<rows; ++i){
    scanf(" %d", &array[i]);
  }

  for(int i = rows-1;i>=0; --i){
    printf("%i\n", array[i]);
  }

  return 0;

}
