/*Daniel Murray 234410*/

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
typedef char cstring[128];
void repeat(cstring s, int count);
void cantor_row(int length, int level);

int main(){
  int size = 0;
  printf("size: ");
  scanf(" %d", &size);
  printf("Width-%i Cantor set:\n", size);
  for(int i = 0; (double)i <= pow((double)size, 1.0/3.0); ++i){
  cantor_row(size, i);
  printf("\n");
  }

  return 0;
}

void repeat(cstring s, int count){
    if(count>0){
      printf("%s", s);
      --count;
      repeat(s, count);
    }
};


void cantor_row(int length, int level){
  if(length==1 || level==0){
  repeat("X", length);
  }
  else{
  cantor_row(length/3, level-1);
  repeat("_", length/3);
  cantor_row(length/3, level-1);
 }
}
