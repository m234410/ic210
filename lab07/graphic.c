/* Daniel Murray*/

#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include<stdlib.h>
typedef char cstring[128];

void read(int* array, int size);
void print(int* array, int size);
bool is_ordered(int* array, int size);
void swap(char char1, char char2, int* array);
void reverse(char char1, char char2, int* array);
int largest(int* array, int size);
void cycleleft(int k, int* array, int size);

int main(){
  printf("Welcome to PutInOrder!\nEnter board description.\n");
  int size = 0;
  scanf("N = %i : ", &size);
  int* array = calloc(size, sizeof(int));
  read(array, size);
  print(array, size);
  int points = 0;
  int moves = 0;
  int condition = 0;
  int k = 1;

  while(condition == 0){
    printf("command: ");
    fflush(stdout);
    char char1;
    char char2;
    cstring command;
    scanf(" %s", command);
    if(strcmp(command, "swap")==0 || strcmp(command, "reverse")==0){
      scanf(" %c %c", &char1, &char2);
    }
    else if(strcmp(command, "cycleleft")==0){
      scanf(" %d", &k);
    }
    else{
      printf("Unknown move \"%s\"\n", command);
    }
    if(strcmp(command, "swap")==0){
        swap(char1, char2, array);
        points += 3;
        ++moves;
    }
    else if(strcmp(command, "reverse")==0){
      reverse(char1, char2, array);
      points += 2;
      ++moves;
    }
    else if(strcmp(command, "cycleleft")==0){
      cycleleft(k, array, size);
      ++points;
      ++moves;
    }

    print(array, size);
    condition = is_ordered(array, size);
  }
  
  printf("%i points! (%i moves)\n", points, moves); 
  
  free(array);
  return 0;
}

void read(int* array, int size){
  for(int i = 0; i<size; ++i){
    scanf(" %d", &array[i]);
  }
}

void print(int* array, int size){
  for(int level = largest(array, size); level > 0; --level){
    for(int i = 0; i < size; ++i){
      if(array[i]>=level)
        printf(" #"); 
      else
        printf("  ");
    }
    printf("\n");
  }
    
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

void swap(char char1, char char2, int* array){
  
  int value1 = array[char1 - 'A'];
  int value2 = array[char2 - 'A'];
  array[char1 - 'A'] = value2;
  array[char2 - 'A'] = value1;
}

void reverse(char char1, char char2, int* array){
  while(char2>char1){
    swap(char1, char2, array);
    ++char1;
    --char2;
    
  }
}

int largest(int* array, int size){
  int bignum = array[0];
  int currentnum = 0;
  for(int i = 1; i < size; ++i){
    currentnum = array[i];
    if(currentnum > bignum){
      bignum = currentnum;
    }
  }
  return bignum;
}

void cycleleft(int k, int* array, int size){
  //starting at max, assign that to the one below it using two transfer ints,
  //when you hit 0, make a final case and transfer back to beginning. 
  int* newarray = calloc(size, sizeof(int));
 
  for( int i = 0; i < size; ++i){
    int targetvalue = i - k; 
    if(targetvalue < 0){
      targetvalue = (size-k) + i;
    }
    newarray[targetvalue] = array[i];
  }
  for(int i = 0; i < size; ++i){
    array[i] = newarray[i];
  }
}

