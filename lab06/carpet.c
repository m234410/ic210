/*Daniel Murray 234410*/

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
typedef char cstring[128];
void repeat(cstring s, int count);
void cantor_row(int length, int level);

int main(){
  int width = 0;
  printf("size: ");
  scanf(" %d", &width);
  printf("Width-%i Sierpinski carpet:\n", width);
  // break//
  for(int i = 0; (double)i < width; ++i){
  carpet_row(width, i);
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
}

void carpet_row(int width, int row){
  if(width==1 || row==0){
    repeat("X", width);
  }
  else{
    carpet_row(width/3, row-1);
    if((width/3)<row<(2*width/3)){
      repeat("_", width/3);
    }
    else{
      carpet_row(width/3, row-1);
void carpet_row(int width, int row){
  if(width==1 || row==0){
    repeat("X", width);
  }
  else{
    carpet_row(width/3, row-1);
    if((width/3)<row<(2*width/3)){
      repeat("_", width/3);
    }
    else{
      carpet_row(width/3, row-1);
    }
      carpet_row(width/3, row-1);
  }
}
    }
      carpet_row(width/3, row-1);
  }
}
