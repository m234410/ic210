/*Daniel Murray 234410*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef char cstring[128];

void printboard(char** board, int rows, int columns);

int main(){
  printf("Filename: ");
  cstring filename;
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r"); 

  int rows = 0;
  int columns = 0;
  int rowlocation1 = 0;
  int columnlocation1 = 0;
  int rowlocation2 = 0;
  int columnlocation2 = 0;
  fscanf(fin, "%d rows %d columns\n", &rows, &columns);
  fscanf(fin, "(%d,%d)\n", &rowlocation1, &columnlocation1);
  fscanf(fin, "(%d,%d)", &rowlocation2, &columnlocation2);
  
  char** board = calloc(rows, sizeof(char*));
  for(int i = 0; i < rows; ++i){
    board[i] = calloc(columns, sizeof(char));
    for(int j = 0; j < columns; ++j){
      board[i][j] = '?';
    }
  }

  printboard(board, rows, columns);

  bool play = true;
  int hit = 0;
  int round;
  
  while(hit<2){
    
    int rowcoordinate = 0;
    int columncoordinate = 0;
      printf("Target: ");
      scanf(" (%d,%d)", &rowcoordinate, &columncoordinate);
      if((rowcoordinate==rowlocation1&&columncoordinate==columnlocation1) || (rowcoordinate==rowlocation2&&columncoordinate==columnlocation2)){
        printf("Hit!\n");
        board[rowcoordinate][columncoordinate] = 'X';
        ++hit;
        ++round;
      }
      else{
        board[rowcoordinate][columncoordinate] = '.';
        printf("Miss!\n");
        ++round;
      }
    printboard(board, rows, columns);
  }

  printf("Sunk in %i rounds\n", round);

  fclose(fin);
  return 0;

}

void printboard(char** board, int rows, int columns){
printf("\n");
  for(int row = 0; row < rows; ++row){
    for(int column = 0; column < columns; ++column){
      printf("%c", board[row][column]);
    }
    printf("\n");
  }
  printf("\n");
}
