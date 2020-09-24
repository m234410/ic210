/* Daniel Murray
 * 234410*/

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
typedef char cstring[128];

int main(){
  cstring fground;  
  cstring bground;
  cstring output;
  int rs = 0;
  int cs = 0;
  printf("Foreground file: ");    // This code initializes and reads in input from the user
  scanf(" %s", fground);
  printf("Background file: ");
  scanf(" %s", bground);
  printf("Row shift: ");
  scanf(" %d", &rs);
  printf("Column shift: ");
  scanf(" %d", &cs);
  printf("Output file: ");
  scanf(" %s", output);

  FILE* bg = fopen(bground, "r"); // This opens streams to the proper files to read the inputs and print to the
  FILE* fg = fopen(fground, "r"); // output. If one of the files was invalid, an error code will be returned.
  FILE* op = fopen(output, "w");

  if(!bg || !fg || !op){
    printf("Error: Input file not found\n");
    return 1;
  }

  int width1 = 0;   // This chunk of code initializes the integers used in the next step
  int height1 = 0;  // the width, height, and max are correspondent to the header info on each file
  int max1 = 0;     // while the color inputs record the values of the pixels in the foreground and 
  int width2 = 0;   // background respectively. The counters ensure that the file is read in correctly
  int height2 = 0;  // this way the code can tell when to start reading in the foreground image, and also when to
  int max2 = 0;     // stop reading in pixels altogether
  int red1 = 0;
  int green1 = 0;
  int blue1 = 0;
  int red2 = 0;
  int green2 = 0;
  int blue2 = 0;
  int widthCounter = 1;
  int heightCounter = 1;

  fscanf(fg, "P3 %d %d %d", &width1, &height1, &max1);    // This chunk of code reads in the header info
  fscanf(bg, "P3 %d %d %d", &width2, &height2, &max2);    // for each file. If the column shift or row shift extends
  fprintf(op, "P3\n%i %i\n%i\n", width2, height2, max2);  // past the boundaries of the file, an error code will be
                                                          // returned. 
  int freeWidth = width2-width1;
  int freeHeight = height2-height1;
  if(rs>freeHeight||cs>freeWidth){
    printf("Error: The foreground goes past the background\n"); // The way the code is written, if the foreground
    return 3;                                                   // image exceeds the boundaries fo the background
  }                                                             // image, it will also return the same error

  for(heightCounter = 1; heightCounter<=height2; ++heightCounter){    // Two nested for loops will run the entire 
    if(heightCounter<=(height1+rs)&&heightCounter>=(1+rs)){           // area of the file by height and width input
      for(widthCounter = 1; widthCounter<=width2; ++widthCounter){    // if the width and height counters specify 
        if(widthCounter<=(width1+cs)&&widthCounter>=(1+cs)){          // the program is reading within the space
        fscanf(fg, "%d %d %d", &red1, &green1, &blue1);               // occupied by the foreground image, it will
        fscanf(bg, "%d %d %d", &red2, &green2, &blue2);               // shift into an if else statement where green
          if(red1==0&&blue1==0&&green1==max1){                        // foreground pixels result in the background
          fprintf(op, "%d %d %d\n", red2, green2, blue2);             // being printed out, while any other 
          }                                                           // foreground pixel will be printed out 
          else{                                                       // as it is read in
          fprintf(op, "%d %d %d\n", red1, green1, blue1);
          }
        }
        else{
         fscanf(bg, "%d %d %d", &red2, &green2, &blue2);
         fprintf(op, "%d %d %d\n", red2, green2, blue2);
        }
      }
    }
    else{
      for(widthCounter = 1; widthCounter<=width2; ++widthCounter){
       fscanf(bg, "%d %d %d", &red2, &green2, &blue2);
       fprintf(op, "%d %d %d\n", red2, green2, blue2);
      }
    }
  }

  printf("Image saved to %s\n", output); // This confirms that the file has saved to the output

  return 0;
}

 
