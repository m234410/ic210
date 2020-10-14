/*Daniel Murray 234410*/

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
typedef char cstring[128];
void repeat(cstring s, int count);
void cantor_row(int length, int level);






void repeat(cstring s, int count){
    if(count>0){
      printf("%s", s);
      --count;
      repeat(s, count);
    }
}


void carpet_row(int width, int row){
  if(row==0){
    cantor_row(width, 0);
  else if(row<




}
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
