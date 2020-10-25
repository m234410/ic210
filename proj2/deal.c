/*Daniel Murray 234410*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>

void swap(int value1, int value2, int* array); // used in shuffle function to swap cards
char* get_suit(int cardnum); // returns suit character for a card number
int get_value(int cardnum); // returns card value for a card number 
void firstdeal(int* deck, int* player, int* dealer); // deals out initial hand to dealer and player arrays
void print_card(int cardnum); //prints a single card based on its card number 
void print_table(int* player, int* dealer); // prints a full table based on player and deck arrays
void play_game(int* deck,int* player,int* dealer); // plays game, asking for hits from player then dealing out two to dealer

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


  int playersize = 52;                      //initializes arrays for player and deck 
  int dealersize = 52;
  int* player = calloc(playersize, sizeof(int));
  int* dealer = calloc(dealersize, sizeof(int));

  firstdeal(deck, player, dealer);
  print_table(player, dealer); // deals initial hand to player and dealer 
  play_game(deck, player, dealer);

  free(player);
  free(dealer);
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

 // prints out the cards of the cardnum, calls on functions to evaluate the face
 // value and suit. treats cards below 10, at 10, and above 10 with different
 // if/else statements. 
void print_card(int cardnum){ 
  if(cardnum==0){
    printf("   ");
  }
  else if(get_value(cardnum)<10){
      printf(" %i", get_value(cardnum));
      printf("%s", get_suit(cardnum));
  }
  else if(get_value(cardnum)==10){
      printf("%i", get_value(cardnum));
      printf("%s", get_suit(cardnum));
  }
  else if(get_value(cardnum)>10){
    switch(get_value(cardnum)){
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
    printf("%s", get_suit(cardnum));
  }
}

void firstdeal(int* deck, int* player, int* dealer){
  player[0] = deck[51];
  dealer[0] = deck[50];
  player[1] = deck[49];
  dealer[1] = deck[48];
}

void print_table(int* player, int* dealer){
  printf("\n");
  printf(" Player Dealer\n");
  int i = 0; //index
  while(player[i]!=0 || dealer[i]!=0){ 
    printf("| ");
    print_card(player[i]);
    printf("  | ");
    print_card(dealer[i]);
    printf("  |\n");
    ++i;
  }
}

void play_game(int* deck, int* player, int* dealer){
  int hit = 1;
  int deck_index = 47;
  int player_index = 2;
  int dealer_index = 2;

  while(hit==true){
    char move;
    printf("Hit or stand? [h/s] ");
    scanf(" %c", &move);
    if(move == 'h'){
      player[player_index] = deck[deck_index];
      print_table(player, dealer);
      --deck_index;
      ++player_index;
    }
    else if(move == 's'){
      hit = 0;
      print_table(player, dealer);   // reprints table 

      for(int i = 0; i < 2; ++i){     //this will all happen twice
        sleep(2);
        printf("Dealer hits.\n");  // announces that dealer will hit below the table
        dealer[dealer_index] = deck[deck_index]; //changes dealer array to show the hit
        print_table(player, dealer);            // prints the new table with the hit
        --deck_index; 
        ++dealer_index;                         //changes the indices to keep up with the change
      }

      sleep(2);
      printf("Dealer stands.\n");               //final stand at the bottom of final table
    }
  }
}

//need to add an expanding function if game keeps going 
