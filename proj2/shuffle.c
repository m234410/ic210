/*Daniel Murray 234410*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int value1, int value2, int* array);
char* get_suit(int cardnum);
int get_value(int cardnum);

int main(){
  int deck[52];
  for(int i =0; i < 52; ++i){
    deck[i] = ((i/13)+1)*100 + i%13 + 2; //creates deck, first term denotes suit, second one denotes value
  }

  int seed = 0;
  printf("Seed: ");
  scanf(" %d", &seed);
  srand(seed);
  if(seed!=0){
    for(int i = 51; i>=0; --i){   //shuffles the deck if seed is not 0
      int j = rand() % (i+1);
      swap(i, j, deck);
    }
  }


  for(int i = 0; i < 52; ++i){  // prints out the cards of the deck, calls on functions to evaluate 
    if(get_value(deck[i])<10){
      printf(" %i", get_value(deck[i]));
      printf("%s\n", get_suit(deck[i]));
    }
    else if(get_value(deck[i])==10){
      printf("%i", get_value(deck[i]));
      printf("%s\n", get_suit(deck[i]));
    }
    else if(get_value(deck[i])>10){
      switch(get_value(deck[i])){
        case 11:
          printf(" J");
          break;
        case 12:
          printf(" Q");
          break;
        case 13:
          printf(" K");
          break;
        case 14:
          printf(" A");
          break;
        default:
          printf("Error");
          break;
        }
      printf("%s\n", get_suit(deck[i]));
    }
  }
    
  return 0;
}

void swap(int value1, int value2, int* array){ //reads in an array and switches the values of the indices provided
    int holder = array[value1];

    array[value1] = array[value2];
    array[value2] = holder;
}

int get_value(int cardnum){
  int cardvalue = cardnum % 100;
  return cardvalue;
}

char* get_suit(int cardnum){
  if(cardnum / 100 == 1){
    char CLUB[] = "\u2663"; // ♣
    return "\u2663";
  }
  else if(cardnum / 100 == 2){
    char DIAMOND[] = "\u2666"; // ♦
    return "\u2666";
  }
  else if(cardnum / 100 == 3){
    char HEART[]   = "\u2665"; // ♥
    return "\u2665";
  }
  else if(cardnum / 100 == 4){
    char SPADE[]   = "\u2660"; // ♠
    return "\u2660";
  }
  return "Error";
}
