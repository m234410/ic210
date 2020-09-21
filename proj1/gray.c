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
    printf("Error: Input file not found\n");
    return 1; 
  }
  else{
    printf("Image saved to %s\n", grayFile);
  }

  int width = 0;
  int height = 0;
  int max = 0;

  fscanf(fin, "P3 %d %d %d", &width, &height, &max);
  fprintf(fout, "P3\n%i %i\n%i\n", width, height, max); 

  int pixels = width*height;

  int red = 0;
  int green = 0;
  int blue = 0;
  
  for(int j =1; j<=height; j++){
    for(int i = 1; i<=width; i++){
    fscanf(fin," %d %d %d", &red, &green, &blue);

    int avg = (red+green+blue)/3;

    fprintf(fout, "%i %i %i\n", avg, avg, avg);
    } 
  }

 return 0;
}
 
         

