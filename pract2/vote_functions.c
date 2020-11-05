/* Daniel Murray 234410*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef char cstring[128];

void get_names(cstring candidate1, cstring candidate2){
  printf("Candidate names: ");
  cstring name1;
  cstring name2;
  scanf(" %s", name1);
  scanf(" %s", name2);

  strcpy(candidate1, name1);
  strcpy(candidate2, name2);
}

bool update_counts(cstring selection, cstring candidate1, int* count1, cstring candidate2, int* count2){
  if(strcmp(selection, "END")==0){
    return false;
  }
  else if(strcmp(selection, candidate1)==0){
    ++ *count1;
  }
  else if(strcmp(selection, candidate2)==0){
    ++ *count2;
  }
  else{
    printf("Invalid name\n");
    return true;
  }
  return true;
}

void display_results(cstring candidate1, int count1, cstring candidate2, int count2){
  int votes = count1 + count2;
  if(count1>count2){
    printf("%s wins with %i of %i votes\n", candidate1, count1, votes);
  }
  else if(count2>count1){
    printf("%s wins with %i of %i votes\n", candidate2, count2, votes);
  }
  else{
    printf("Tie!\n");
  }
}
