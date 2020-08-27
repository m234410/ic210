/* Daniel Murray*/

#include"ic210.h"
#include <math.h>

int main() {

  fputs("Enter a number between 0 and 15: ", stdout);
  int decimal = readnum(stdin);

  int eight = decimal/8;
  int leftover = decimal%8;
  int four = leftover/4;
  int leftover2 = leftover%4;
  int two = leftover2/2;
  int leftover3 = leftover2%2;
  int one = leftover3/1;



  writenum(decimal, stdout);
  fputs(" in binary is ",stdout);
  writenum(eight, stdout);
  writenum(four, stdout);
  writenum(two, stdout);
  writenum(one, stdout);
  fputs("\n", stdout);

return 0;
}
