/* Daniel Murray*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef char cstring[128];

int main(){
  cstring filename;
  double income = 0;
  scanf("%s $%lg", filename, &income);

  FILE* fin = fopen(filename, "r");
  if(!fin){
    printf("File not found!");
    return 1;
  }

  double bracket = 0;
  double lowBound = 0;
  double hiBound = 0;
  cstring junk;
  int check = fscanf(fin, " %lg%c $%lg to $%lg", &bracket, junk, &lowBound, &hiBound);
  while(check==4){
    if(income<hiBound && income>lowBound){
      double tax = bracket*0.01*income;
      fprintf(stdout, "%g% This is you! You owe $%.1f\n", bracket, tax);
    }
    else{
      fprintf(stdout, "%g% This is not you!\n", bracket);
    }
    double currentbracket = bracket;
    int check = fscanf(fin, " %lg%c $%lg to $%lg", &bracket, junk, &lowBound, &hiBound);
    if(currentbracket==bracket)
      return 0;
  }



  return 0;
}
