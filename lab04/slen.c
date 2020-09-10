/* Daniel Murray*/

#include"ic210.h"

int main(){
  fputs("Enter a filename: ", stdout);
  cstring fileName;
  readstring(fileName, stdin);
  stream book = fopen(fileName, "r");
  double wordcount = 0;
  int i = 0;
  double sentencecount = 0;
  
  while(i<3){
    cstring word;
    readstring(word, book); 
    if(stringeq(word, "***")){
      i++;
    }
    if(i>1&&!stringeq(word, "***")){
      wordcount++;
      if(strchr(word, '.')||strchr(word, '!')||strchr(word, '?'))
        sentencecount++;
      else if(i==3)
        sentencecount++;
    }
  }
  
  double average = wordcount/sentencecount;
  fputs("Average sentence length: ", stdout);
  writenum(average, stdout);
  fputs("\n", stdout);

  return 0;
}
