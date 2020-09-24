/* gray.c 
 * Daniel Murray*/

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
typedef char cstring[128];

int main(){
  cstring grayFile;
  cstring colorFile;
  printf("Input file: "); 
  scanf(" %s", colorFile);
  printf("Output file: ");
  scanf(" %s", grayFile);
  FILE* fin = fopen(colorFile, "r");
  FILE* fout = fopen(grayFile, "w");
  if(!fin){
    printf("Error: Input file not found\n"); // The code up until this point reads the user input for input file
    return 1;                                // and output file. If the input file is not valid it will return an
  }                                          // error code, if not, the line in the "else" statement will confirm 
  else{                                      // that the output file has been saved correctly. 
    printf("Image saved to %s\n", grayFile);
  }

  int width = 0;
  int height = 0;
  int max = 0;

  fscanf(fin, "P3 %d %d %d", &width, &height, &max);    // I am intializing integers to read in the header on the
  fprintf(fout, "P3\n%i %i\n%i\n", width, height, max); // input file. I also specify how many pixels exist by 
                                                        // multiplying the width
                                                        // and height to find
                                                        // area 
                                                      
                                                       
                                                        
  int pixels = width*height;

  int red = 0;
  int green = 0;
  int blue = 0;
  
  for(int j =1; j<=height; j++){                    // After initializing the integers for red, green and blue,
    for(int i = 1; i<=width; i++){                  // I create a nested for loop that runs the width of the file
    fscanf(fin," %d %d %d", &red, &green, &blue);   // then repeats that over the whole height of the file
                                                    
    int avg = (red+green+blue)/3;                   // The loop reads in the pixel values, averages them out,
                                                    // then prints them to the
    fprintf(fout, "%i %i %i\n", avg, avg, avg);     // output file
    } 
  }

 return 0;
}
 
         

