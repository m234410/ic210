/* Daniel Murray*/

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
typedef char cstring[128];

int main(){
  cstring function;
  double bill = 0;
  cstring word2;
  scanf(" %s $%lg %s", function, &bill, word2);
  if(!strcmp(function, "calc")){
    if(!strcmp(word2, "tip")){
      double tip = 0;
      scanf(" %lg", &tip);
      double payAmount = bill*(1+0.01*tip);
      printf("pay $%.3lf \n", payAmount);
     }
     else if(!strcmp(word2, "split")){
      double ways = 0;
      double tip = 0;
      scanf(" %lg ways tip %lg", &ways, &tip);
      double payAmount = (bill*(1+0.01*tip))/ways;
      printf("pay $%.3lf \n", payAmount);
     }
    }
    else if(!strcmp(function, "test")){
      double payAmount = 0;
      scanf(" $%lg", &payAmount);
      double tip = payAmount - bill;
      double tipPercent = 100*(tip/bill);
      printf("tip %lg", tipPercent);
      puts("%");
    }
  return 0;

  }
