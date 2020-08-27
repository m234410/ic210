/* Daniel Murray*/

#include"ic210.h"
#include <math.h>

int main(){
  fputs("Permissions: ", stdout);

  char User = readchar(stdin);
  char Group = readchar(stdin);
  char Other = readchar(stdin);
  
  int uservalue = (int)User - '0'; 
  int userread = uservalue/4;
  int leftover = uservalue%4;
  int userwrite = leftover/2;
  int leftover1 = leftover%2;
  int userexecute = leftover1/1;

  fputs("\n",stdout);
  fputs("User:\n", stdout);
  fputs("read    ",stdout);
  writenum(userread, stdout);
  fputs("\n", stdout);
  fputs("write   ",stdout);
  writenum(userwrite, stdout);
  fputs("\n", stdout);
  fputs("execute ",stdout);
  writenum(userexecute, stdout);
  fputs("\n", stdout);

  int groupvalue = (int)Group - '0'; 
  int groupread = groupvalue/4;
  leftover = groupvalue%4;
  int groupwrite = leftover/2;
  leftover1 = leftover%2;
  int groupexecute = leftover1/1;

  fputs("\n",stdout);
  fputs("Group:\n", stdout);
  fputs("read    ",stdout);
  writenum(groupread, stdout);
  fputs("\n", stdout);
  fputs("write   ",stdout);
  writenum(groupwrite, stdout);
  fputs("\n", stdout);
  fputs("execute ",stdout);
  writenum(groupexecute, stdout);
  fputs("\n", stdout);

  int othervalue = (int)Other - '0'; 
  int otherread = othervalue/4;
  leftover = othervalue%4;
  int otherwrite = leftover/2;
  leftover1 = leftover%2;
  int otherexecute = leftover1/1;

  fputs("\n",stdout);
  fputs("Other:\n",stdout);
  fputs("read    ",stdout);
  writenum(otherread, stdout);
  fputs("\n", stdout);
  fputs("write   ",stdout);
  writenum(otherwrite, stdout);
  fputs("\n", stdout);
  fputs("execute ",stdout);
  writenum(otherexecute, stdout);
  fputs("\n", stdout);

return 0;
}
