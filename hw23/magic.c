/* Daniel Murray 234410 */

#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

int main(){
  int size = 1;                                 //asks user for size input
  printf("size: ");
  scanf(" %d", &size);
  
  int** columns = calloc(size, sizeof(int*));   //creates size x size 2-D array
  for(int i = 0; i < size; ++i){
    columns[i] = calloc(size, sizeof(int));
  }
  
  for(int row = 0; row < size; ++row){                // nested for loops that fill in array
    for(int column = 0; column< size; ++column){
      scanf(" %d", &columns[column][row]);
    }
  }
    
  int diagonalsum1 = 0;
  int diagonalsum2 = 0;
  int rowsum = 0;
  int columnsum = 0;
  int firstsum = 0;
  int magic = 1;
  

  for(int i = 0; i < size; ++i){    //make a nested for loop to count across row, col, and diagonal
    for(int j = 0; j < size; ++j){ 
      columnsum += columns[i][j];
      rowsum += columns[j][i];
    }
    
    diagonalsum1 += columns[i][size-1-i];
    diagonalsum2 += columns[i][i];

    if(i==0)            //establishes initial potential magic number
      firstsum = columnsum;
    if(!(rowsum == firstsum && columnsum == firstsum)){  
      magic = 0;
    }
    columnsum = 0; // resets totals
    rowsum = 0;   // resets totals
  }
  if(diagonalsum1!=firstsum || diagonalsum2!=firstsum){
    magic = 0;
  }

  if(magic==1){
    printf("All sums equal %i\n", firstsum);
  }
  else{
    printf("Not magic\n");
  }
  return 0;

}
