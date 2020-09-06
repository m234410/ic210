/* Daniel Murray*/

#include"ic210.h"

int main(){
  cstring convert;
  readstring(convert, stdin);
  double amount = readnum(stdin);
  cstring c1;
  cstring readto;
  cstring c2;
  readstring(c1, stdin);
  readstring(readto, stdin);
  readstring(c2, stdin);

  double EpD = 0.84;
  double YpD = 105.36;
  double dollaramount = 0;
  double outputamount = 0;

  if(stringeq(c1, "Euros"))
    dollaramount = amount/EpD;
  else if(stringeq(c1, "Yen"))
    dollaramount = amount/YpD;
  else if(stringeq(c1, "Dollars"))
    dollaramount = amount;

  if(stringeq(c2, "Euros"))
    outputamount = dollaramount*EpD;
  else if(stringeq(c2, "Yen"))
    outputamount = dollaramount*YpD;
  else if(stringeq(c2, "Dollars"))
    outputamount = dollaramount;

  writenum(outputamount, stdout);

return 0;
}



