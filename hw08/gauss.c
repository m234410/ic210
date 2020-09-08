/* Daniel Murray*/

#include"ic210.h"

int main(){
  fputs("Enter n: ", stdout);
  int n = readnum(stdin);
  int gs = 0;
  for(int i = 1;i <= n;++i){
    gs += i;
  }

  fputs("The sum of numbers from 1 up to ", stdout);
  writenum(n, stdout);
  fputs(" is ", stdout);
  writenum(gs, stdout);
  fputs("\n", stdout);

  return 0;
}

