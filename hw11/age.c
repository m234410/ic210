/* Daniel Murray */

#include"ic210.h"

int main(){
  int age = 0;
  int day = 0;
  int month = 0;
  int year = 0;
  cstring name;

  fscanf(stdin," %s %d/%d/%d", name, &month, &day, &year);
    if(month>9 || (day>14 && month == 9))
      age = 2020 - year -1;
    else 
      age = 2020 - year;
  fprintf(stdout, "%s is %i years old.\n", name, age);

  return 0;
}
