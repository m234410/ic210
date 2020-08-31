/* Daniel Murray */

#include"ic210.h"
#include<math.h>

int main(){
  fputs("Input word : ", stdout);

  char letter1 = readchar(stdin);
  cstring word;
  readstring(word, stdin);

  int letter1value = (int)letter1;
  int capletter1value = letter1value-32;
  char capletter1 = (char)capletter1value;

  fputs("Capitalized: ", stdout);

  if (letter1value<=122&&letter1value>=97){
    fputc(capletter1, stdout);
  }

  else 
    fputc(letter1, stdout);

  fputs(word, stdout);
  fputs("\n", stdout);

return 0;
}https://submit.moboard.com/site/receipt.php?submission=3b6dfff3-ad06-4196-9479-81de9d14b26b
