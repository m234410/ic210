/* Daniel Murray*/

#include"ic210.h"

int main(){
  
  double EpD = 0.84;
  double YpD = 105.36;
  double CDpD = 1.31;
  double dollaramount = 0;
  double outputamount = 0;
  double loopamount = 0;
 
  cstring junkin;
  readstring(junkin, stdin);
  cstring and;
 
 while(!stringeq(and, "to")){
  
  double amount = readnum(stdin);
  
  cstring c1;
  char dollartype = 'n';
  
  readstring(c1, stdin);

  if(stringeq(c1, "Dollars")){
    cstring nationality;
    readstring(nationality, stdin);
    if(stringeq(nationality, "US"))
      dollartype = 'a';
    if(stringeq(nationality, "Canadian"))
      dollartype = 'c';
  }

  
  if(stringeq(c1, "Euros"))
    dollaramount = amount/EpD;
  else if(stringeq(c1, "Yen"))
    dollaramount = amount/YpD;
  else if(dollartype == 'c')
    dollaramount = amount/CDpD;
  else if(dollartype == 'a')
    dollaramount = amount;

 
  
  loopamount += dollaramount;
  readstring(and, stdin);
  }
  
  cstring c2;
  readstring(c2, stdin);
  char dollartype2 = 'n';

  if(stringeq(c2, "Dollars")){
    cstring nationality;
    readstring(nationality, stdin);
    if(stringeq(nationality, "US"))
      dollartype2 = 'a';
    if(stringeq(nationality, "Canadian"))
      dollartype2 = 'c';
  }

 if(stringeq(c2, "Euros"))
    outputamount = loopamount*EpD;
  else if(stringeq(c2, "Yen"))
    outputamount = loopamount*YpD;
  else if(dollartype2 == 'c')
    outputamount = loopamount*CDpD;
  else if(dollartype2 == 'a')
    outputamount = loopamount;

  writenum(outputamount, stdout);

return 0;
}

