/* Daniel Murray*/

#include"ic210.h"

int main(){
  fputs("Filename: ", stdout);
  cstring file;
  readstring(file, stdin);
  stream grades = fopen(file, "r");

  double topgrade = 0;
  cstring topname;
  int n = readnum(grades);
  cstring word; 

  readstring(word, grades);
  while(!stringeq(word, "EXAM"))
    readstring(word, grades);
  for(int i = 0;i < n; i++){
    cstring studentName;
    readstring(studentName, grades);
    double hwgrade = readnum(grades);
    double quizgrade = readnum(grades);
    double examgrade = readnum(grades);
    double finalgrade = 0.2*hwgrade + 0.2*quizgrade + 0.6*examgrade;
    if(finalgrade>topgrade){
      topgrade = finalgrade;
      strcpy(topname, studentName);
    }
  }
  
  fputs(topname, stdout);
  fputs(" has the highest grade of ", stdout);
  writenum(topgrade, stdout);
  fputs("\n", stdout);

  return 0;
}
