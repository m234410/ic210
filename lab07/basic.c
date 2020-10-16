/* Daniel Murray*/

#include <stdio.h>
#include <stdbool.h>
#include<string.h>
typedef char cstring[128];

// fills in the array with integers read from stdin
void read(int* array, int size);

// prints the array to stdout, lined up with dashes and
// corresponding capital letters underneath
void print(int* array, int size);

// returns 1 if the array elements are in ascending (non-decreasing)
// order, and otherwise returns 0.
bool is_ordered(int* array, int size);

void swap(char a, char b);

int main(){
  printf("Welcome to PutInOrder!\nEnter board description.\n");
  int size = 0;
  scanf("N = %i : ", &size);
  int array[size];
  read(array, size);
  print(array, size);
  int points = 0;
  int moves = 0;
  int condition = 0;

  while(condition == 0){
    printf("commvoid swap(){and: ");
    char char1;
    char char2;
    cstring swap;
    scanf(" %s", swap);
    //if it is not swap, error statement, if it is swap, make it scan, then a
    //separate if else statement going into commands.//
    if(strcmp(swap, "swap")!=0){
      printf("Unknown move \"%s\"\n", swap);
    }
    else{
      scanf(" %c %c", &char1, &char2)
    }
    if(strcmp(swap, "swap")==0){
        swap(char1, char2);
    }
    else if{
      //put reverse command here//
      //swap out the word "swap" for "command" to be more universal//
    }





    print(array, size);
    condition = is_ordered(array, size);
  }
  
  printf("%i points! (%i moves)\n", points, moves); 
  
  return 0;
}

void read(int* array, int size){
  for(int i = 0; i<size; ++i){
    scanf(" %d", &array[i]);
  }
}

void print(int* array, int size){
  for(int i = 0; i < size; ++i){
    printf(" %i", array[i]);
  }
  printf("\n");
  for(int i = 0; i < (2*size + 1); ++i){
    printf("-");
  }
  printf("\n");
  for(int i = 0; i < size; ++i){
    char letter = i + 'A';
    printf(" %c", letter);
  }
  printf("\n");
}

bool is_ordered(int* array, int size){
  int last = array[0];
  for(int i = 1; i < size; ++i){
    if(array[i] >= last)
      last = array[i];
    else
      return 0;
  }
  return 1;
}

void swap(char a, char b){
  
  int value1 = array[char1 - 'A'];
  int value2 = array[char2 - 'A'];
  array[char1 - 'A'] = value2;
  array[char2 - 'A'] = value1;

  points += 3;
  ++moves;
}
