<<<<<<< HEAD
//Daniel Murray//

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
typedef char cstring[128];

int main(){
  cstring filename;
  char readin;
  printf("Filename: ");
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r");

  if(!fin){
    printf("File not found!\n");
    return 1;
  }

  int columnNow= 0;
  int rowNow = 0;
  int columnX = 0;
  int rowX = 0;
   
  while(fscanf(fin, " %c", &readin)==1 && readin != 'Q'){
    if(readin=='S'){
      int repeat = 1;
      fscanf(fin, "%d", &repeat);
      for(int i=0; i<repeat; ++i){
        printf("*");
        ++columnNow;
      }
    }
    else if(readin=='X'){
      printf("X");
      columnX = columnNow;
      rowX = rowNow;
    }
    else if(readin=='N'){
      printf("\n");
      columnNow=0;
      ++rowNow;
    }
    else if(readin=='B'){
      int repeat = 1;
      fscanf(fin, "%d", &repeat);
      for(int i=0; i<repeat; ++i){
        printf(" ");
        ++columnNow;
      }
    }
  }

  printf("The treasure is at row %i and col %i\n", rowX, columnX);
  
  return 0;
}
=======
/* Erase this comment and put your name here!
 * p3.c: treasure map
 */
>>>>>>> 443539f74322ee9876edb6025703e96d6c4866ba
