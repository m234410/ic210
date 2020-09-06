/* Daniel Murray */

#include"ic210.h"
#include<math.h>

int main(){
  int n = 1;
  while(n==1){
    fputs("What is your favorite leap year? ", stdout);
    int year = readnum(stdin);
    
    if(year%400==0){
      n+=1;
      fputs("Yes, ", stdout);
      writenum(year, stdout); 
      fputs(" was a good year.", stdout);
      fputs("\n", stdout);
      return 0;
    }

    else if((year%4==0)&&(!(year%100==0))){
      n+=1;
      fputs("Yes, ", stdout);
      writenum(year, stdout); 
      fputs(" was a good year.", stdout);
      return 0;
    }

    else{
      writenum(year, stdout);
      fputs(" is not a leap year!", stdout);
      fputs("\n", stdout); 
      }
  }
return 0;
}

      
