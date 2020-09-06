/* Daniel Murray
 * 234410*/

#include"ic210.h"

int main(){
  fputs("Username: ", stdout);
  cstring username;
  readstring(username, stdin);
  
  if (stringeq(username, "supe")){
    fputs("Password: ", stdout);
    cstring passwordsupe; 
    readstring(passwordsupe, stdin);
    if (stringeq(passwordsupe, "beatarmy"))
      fputs("yes\n", stdout);
    else 
      fputs("no\n", stdout);
  }
  else if (stringeq(username, "bbq")){
    fputs("Password: ", stdout);
    cstring passwordbbq;
    readstring(passwordbbq, stdin);
    if (stringeq(passwordbbq, "brisket"))
      fputs("yes\n", stdout);
    else
      fputs("no\n", stdout);
  }
  else {
    fputs("Password: ", stdout);
    cstring dontcare;
    readstring(dontcare, stdin);
    fputs("no\n", stdout);
  }

return 0;
    }
