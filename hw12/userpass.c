/* Daniel Murray*/

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
typedef char cstring[128];

int main(){
  cstring username;
  cstring password;
  printf("Username: ");
  scanf(" %s", username);
  printf("Password: ");
  scanf(" %s", password);

  char usernum = 0;
  char passnum = 0;
  
  if(!strcmp(username, "supe"))
    usernum = 1;
  else if(!strcmp(username, "bbq"))
    usernum = 2;
  if(!strcmp(password, "beatarmy"))
    passnum = 1;
  else if(!strcmp(password, "brisket"))
    passnum = 2;

  if(usernum==passnum && usernum != 0)
    printf("yes\n");
  else 
    printf("no\n");

  return 0;
}

