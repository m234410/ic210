//Daniel Murray//

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
typedef char cstring[128];

int main(){
  cstring filename;
  printf("Filename: ");
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r");

  if(!fin){
    printf("File not found!\n");
    return 0;
  }



  cstring shortest;
  cstring longest; 
  int shortHour = 100;
  int shortMinute = 61;
  int longHour = 0;
  int longMinute = 0;
  int launchHour = 0;
  int launchMinute = 0;
  int landHour = 0;
  int landMinute = 0;
  cstring flight;
  
  while(fscanf(fin, " %s %d:%d - %d:%d", flight, &launchHour, &launchMinute, &landHour, &landMinute)==5){
    int hourDifference = landHour - launchHour;
    int minuteDifference = landMinute - launchMinute;
    if(landMinute<launchMinute){
      hourDifference -= 1;
      minuteDifference = 60 - launchMinute +landMinute;
    }
    if(landHour<launchHour){
      hourDifference += 24;
    }

    if(hourDifference>longHour||(hourDifference==longHour&&minuteDifference>longMinute)){
      longHour = hourDifference; 
      longMinute = minuteDifference;
      strcpy(longest, flight);
    }
    else if(hourDifference<shortHour||(hourDifference==shortHour&&minuteDifference<shortMinute)){
      shortHour = hourDifference;
      shortMinute = minuteDifference; 
      strcpy(shortest, flight);
    }
  }
  printf("Longest: %s with %i hours and %i minutes\nShortest: %s with %i hours and %i minutes\n", longest, longHour, longMinute, shortest, shortHour, shortMinute); 
  return 0;
}

