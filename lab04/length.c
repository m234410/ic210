/* Daniel Murray*/

#include"ic210.h"

int main(){
  fputs("Enter a filename: ", stdout);
  cstring fileName;
  readstring(fileName, stdin);
  stream book = fopen(fileName, "r");
  double wordcount = 0;
  int i = 0;
  double wordlength = 0;
  
  while(i<3){
    cstring word;
    readstring(word, book); 
    if(stringeq(word, "***")){
      i++;
    }
    if(i>1&&!stringeq(word, "***")){
      wordcount++;
      wordlength += strlen(word);
    }
  }
  
  double average = wordlength/wordcount;
  fputs("Average word length: ", stdout);
  writenum(average, stdout);
  fputs("\n", stdout);

  return 0;
}
