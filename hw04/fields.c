/* Daniel Murray*/

#include"ic210.h"
#include<math.h>

int main(){
  fputs("How many football fields? ",stdout);
  double ff = readnum(stdin);
 
  double ff_feet = ff*300;
  int miles = ff_feet/5280;
  int feet = (int)ff_feet%5280;
  double inches = ((ff_feet - 5280*miles) - feet)*12;

  writenum(miles, stdout);
  fputs(" miles ", stdout);
  writenum(feet, stdout);
  fputs(" feet ", stdout);
  writenum(inches, stdout);
  fputs(" inches\n", stdout);


return 0;
}
