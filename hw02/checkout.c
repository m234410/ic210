/* Daniel Murray*/

#include "ic210.h"

int main() {

  fputs("What item are you purchasing? \n", stdout);
  cstring item; 
  readstring (item, stdin); 
  fputs("\n", stdout);
  
  fputs("How much does your item cost? \n", stdout);
  double cost;
  cost = readnum(stdin); 
  fputs("\n", stdout);

  fputs("How many items are you purchasing? \n", stdout);
  double amount; 
  amount = readnum(stdin);
  fputs("\n", stdout);
  
  double final_cost;
  final_cost = cost*amount;
  writenum(amount, stdout);
  fputs(" ", stdout);
  fputs(item, stdout);
  fputs(" ", stdout);
  fputs("cost $", stdout);
  writenum(final_cost, stdout);
  fputs("\n", stdout);

  return 0; 
}

