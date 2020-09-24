/* Daniel Murray 
 * 234410*/

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
typedef char cstring[128];

int main(){
  cstring output;
  cstring fground;
  cstring bground;
  printf("Foreground file: ");  // These lines initialize the cstrings used to read in user input, prompts the user
  scanf(" %s", fground);        // then reads the input
  printf("Background file: ");
  scanf(" %s", bground);
  printf("Output file: ");
  scanf(" %s", output);
  fflush(stdout);

  FILE* imagein = fopen(fground, "r");      // This code opens the proper streams, or returns an error code
  FILE* backgroundin = fopen(bground, "r"); // if an invalid file has been entered
  FILE* fout = fopen(output, "w");
  if(!imagein || !backgroundin || !fout){
    printf("Error: Input file not found\n");
    return 1;
  }

  int width1 = 0;   // The following chunk of code intializes and reads in the header values for each file
  int width2 = 0;   // If the file sizes do not match, an error code will be returned
  int height1 = 0;
  int height2 = 0;
  int max1 = 0;
  int max2 = 0;

  fscanf(imagein, "P3 %d %d %d", &width1, &height1, &max1);     
  fscanf(backgroundin, "P3 %d %d %d", &width2, &height2, &max2);
  if(width1!=width2||height1!=height2){
    printf("Error: Images have different sizes\n");
    return 2;
  }
  
  fprintf(fout, "P3\n %i %i\n%i\n", width1, height1, max1); // This line prints the header of the output file

  int red1 = 0;   // This chunk of code reads in information from the foreground and background simultaneously
  int green1 = 0; // If a pixel in the foreground is green, the code will print the complementary background pixel
  int blue1 = 0;  // to the output file. If the pixel is not green, the code will print the foreground pixel to 
  int red2 = 0;   // the output file.
  int green2 = 0;
  int blue2 = 0;
  while(fscanf(imagein, " %d %d %d", &red1, &green1, &blue1)==3){
    fscanf(backgroundin, " %d %d %d", &red2, &green2, &blue2);
    if(green1==max1&&red1==0&&blue1==0){
      fprintf(fout, "%d %d %d\n", red2, green2, blue2);
    }
    else{
      fprintf(fout, "%d %d %d\n", red1, green1, blue1);
    }
  }
  
  printf("Image saved to %s\n", output); // This confirms that the new image has been saved to the output

  return 0;
}

