/*Daniel Murray 234410*/

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
typedef char cstring[128];
void repeat(cstring s, int count);
void cantor_row(int length);

int main(){
  int size = 0;
  printf("size: ");
  scanf(" %d", &size);
  printf("Width-%i Cantor set:\n", size);
  cantor_row(size);
  printf("\n");

  return 0;
}

void repeat(cstring s, int count){
    printf("%s", s);
    if(count>1){
      --count;
      repeat(s, count);
    }
}

void cantor_row(int length){
  if(length==1){
  printf("X");
  }
  else{
  cantor_row(length/3);
  repeat("_", length/3);
  cantor_row(length/3);
 }
}
