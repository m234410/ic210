/* Daniel Murray*/

#include"ic210.h"
#include<math.h>

int main(){
  fputs("Time:",stdout);

  char digit1 = readchar(stdin);
  char digit2 = readchar(stdin);
  char digit3 = readchar(stdin);
  char digit4 = readchar(stdin);

  int hour1 = (int)digit1 - '0';
  int hour2 = (int)digit2 - '0';
  int minute1 = (int)digit3 - '0';
  int minute2 = (int)digit4 - '0';

  int time = 1000*hour1 + 100*hour2 + 10*minute1 + minute2;

  if (time>2300||time<600)
    fputs(" Asleep\n", stdout);
  else 
    fputs(" Awake\n", stdout);

return 0;
}
