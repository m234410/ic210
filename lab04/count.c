/* Daniel Murray*/

#include"ic210.h"

int main(){
  fputs("Enter a filename: ", stdout);
  cstring fileName;
  readstring(fileName, stdin);
  stream book = fopen(fileName, "r");
  int wordcount = 0;
  int i = 0;
  
  while(i<3){
    cstring word;
    readstring(word, book); 
    if(stringeq(word, "***")){
      i++;
    }
    if(i>1&&!stringeq(word, "***"))
      wordcount++;
  }
  
  fputs("Word count: ", stdout);
  writenum(wordcount, stdout);
  fputs("\n", stdout);

  return 0;
}
