/* Daniel Murray*/

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
typedef char cstring[128]; 

//My program should run fine without string.h, 
//but I am including it now in case I need it later.

int main(){

  //the printf prompts the user to enter a filename, while the scanf reads the
  //filename in as a string. FILE* opens a stream to read in from the file. The
  //if statement will return an error code if the stream opening was
  //unsuccessful.

  cstring filename;
  printf("Input file: "); 
  scanf("%s", filename);
  FILE* fin = fopen(filename, "r");
  if(!fin){
    printf("\nError, invalid file input!");
    return 1;
  }

  //I initialize the width, height, and max color value integers before reading them
  //in from the file. Then i use fscanf to read past the P3 (if there is no P3,
  //the function should break down) and read in the width, height, and max
  //value.
  
  int width = 0;
  int height = 0;
  int max = 0;

  fscanf(fin, "P3 %d %d %d", &width, &height, &max);

  printf("width = %d, height = %d\nmax value = %d\n", width, height, max);

  int pixels = height*width;
  
  //I create an int for the number of total pixels. My for loop will run until
  //it has counted the proper number of pixels specified by the width and height
  //given by the file. I initialize and read in the integers for the values of
  //color in each pixel, then I calculate the row using int division, and I
  //calculate the column position using mod. fprintf then displays the resulting
  //information into the stdout terminal. The loop will end when it has read
  //every pixel. 


  for(int i = 0; i < pixels; ++i){
    int red = 0;
    int green = 0;
    int blue = 0;
    fscanf(fin," %d %d %d", &red, &green, &blue);
    
    int row = i / width;
    int col = i % width;

    fprintf(stdout, "row %d, col %d: r%d g%d b%d\n", row, col, red, green, blue);
    }

  return 0;
}
