/* Daniel Murray*/

#include"ic210.h"
#include<math.h>

int main(){
  fputs("Height: ", stdout);
  int height = readnum(stdin);
  fputs("Width: ", stdout);
  int width = readnum(stdin);
  fputs("Offset: ", stdout);
  int offset = readnum(stdin); 
  
  for(int i=1;i<=height;i++){
    if(i==1||i==height){
      for(int j=1;j<=(offset+width);j++){
        if(j<=offset)
          fputs(" ", stdout);
        else
          fputs("*", stdout);
      }
      fputs("\n", stdout);
    }
    else{
      for(int k=1;k<=(offset+width);k++){
        if(k<=offset)
          fputs(" ", stdout);
        else if(k==(offset+1)||k==(offset+width))
          fputs("*", stdout);
        else
          fputs(" ", stdout);
      }
      fputs("\n", stdout);
    }
  }



  return 0;
}
