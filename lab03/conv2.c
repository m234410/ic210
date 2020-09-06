/* Daniel Murray*/

#include"ic210.h"

int main(){
  cstring convert;
  readstring(convert, stdin);
  
  double amount = readnum(stdin);
  
  cstring c1;
  cstring readto;
  cstring c2;
  char dollartype = 'n';
  char dollartype2 = 'n';
  
  readstring(c1, stdin);

  if(stringeq(c1, "Dollars")){
    cstring nationality;
    readstring(nationality, stdin);
    if(stringeq(nationality, "US"))
      dollartype = 'a';
    if(stringeq(nationality, "Canadian"))
      dollartype = 'c';
  }

  readstring(readto, stdin);
  
  readstring(c2, stdin);

  if(stringeq(c2, "Dollars")){
    cstring nationality;
    readstring(nationality, stdin);
    if(stringeq(nationality, "US"))
      dollartype2 = 'a';
    if(stringeq(nationality, "Canadian"))
      dollartype2 = 'c';
  }

  double EpD = 0.84;
  double YpD = 105.36;
  double CDpD = 1.31;
  double dollaramount = 0;
  double outputamount = 0;

  if(stringeq(c1, "Euros"))
    dollaramount = amount/EpD;
  else if(stringeq(c1, "Yen"))
    dollaramount = amount/YpD;
  else if(dollartype == 'c')
    dollaramount = amount/CDpD;
  else if(dollartype == 'a')
    dollaramount = amount;

  if(stringeq(c2, "Euros"))
    outputamount = dollaramount*EpD;
  else if(stringeq(c2, "Yen"))
    outputamount = dollaramount*YpD;
  else if(dollartype2 == 'c')
    outputamount = dollaramount*CDpD;
  else if(dollartype2 == 'a')
    outputamount = dollaramount;

  writenum(outputamount, stdout);

return 0;

}



