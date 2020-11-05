/*Daniel Murray 234410
 * extra function: uses 7 decks combined, keeps track of money for one hand,
 * asks player to bet or fold after initial deal*/

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
void print_table(int* player, int* dealer, bool isplayerdone, int* money); // prints a full table based on player and deck arrays
void play_game(int* deck,int* player,int* dealer, int* money); // plays game, asking for hits from player then dealing out two to dealer
void shuffle(int seed, int* deck);
int score(int* array);

int main(){
  int deck[364];
  for(int i =0; i < 364; ++i){
    int index = i;
    if(i>=52){
      index = i%52;
    }
    deck[i] = ((index/13)+1)*100 + index%13 + 2; //creates deck, first term denotes suit, second one denotes value
  }

  int seed = 0; //asks user for seed and shuffles deck
  printf("Seed: ");
  scanf(" %d", &seed);
  srand(seed);
  shuffle(seed, deck);
  
  int money = 100;
  int playersize = 52; //initialize player and dealer decks to an amount that won't be exceeded
  int dealersize = 52;
  int* player = calloc(playersize, sizeof(int));
  int* dealer = calloc(dealersize, sizeof(int));

  firstdeal(deck, player, dealer);
  print_table(player, dealer, false, &money); // deals initial hand to player and dealer
  play_game(deck, player, dealer, &money); 

  free(player);
  free(dealer);
  return 0;
}

void swap(int value1, int value2, int* array){ //reads in an array and switches the values of the indices provided
    int holder = array[value1];

    array[value1] = array[value2];
    array[value2] = holder;
}

int get_value(int cardnum){ //reads in cardnumber and outputs value
  int cardvalue = cardnum % 100;
  return cardvalue;
}

char* get_suit(int cardnum){ // reads in card number and outputs suit
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
  if(cardnum==0){ // prints a space if the index is blank 
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

void print_table(int* player, int* dealer, bool isplayerdone, int* money){
  printf("\n");
  printf(" Player Dealer Money: %i\n", *money);
  int i = 0; //index
  while(player[i]!=0 || dealer[i]!=0){  //will print as long as not BOTH player and dealer have blank values
    printf("| ");
    print_card(player[i]);
    printf("  | ");
    if(isplayerdone==false && i == 1){ //if the player has not finished, do not reveal dealer 2nd card
      printf(" **");
    }
    else{
      print_card(dealer[i]);
    }
    printf("  |\n");
    ++i;
  }
}

void play_game(int* deck, int* player, int* dealer, int* money){
  bool isplayerdone = false; // boolean condition, if player is done, move goes to dealer.
  bool hit = true; //boolean condition for game loop, ends when someone wins or a tie
  int deck_index = 47; //keeps track of where to draw from the deck, 4 cards have already been dealt. 
  int player_index = 2; //keeps track of where in the player array to issue cards
  int dealer_index = 2; //does the same for dealer array
  bool first_turn = true;

  while(hit==true){
    char move;
    if(score(player)>21){ // if player busts, move goes to dealer
      move = 's';
      printf("Player busts!\n");
    }
    else if(isplayerdone){ // if the player is done with his hand, move will always go to dealer
      move = 's';
    }
    else{
      if(first_turn){
        (*money) -= 5;
        printf("- $5 ante\nWould you like to pay $5 to play or fold? [p/f]\n");
        char decision;
        scanf(" %c", &decision);
        first_turn = false;
        if(decision == 'f'){
          for(int i =0; i < 364; ++i){
            int index = i;
            if(i>=52){
              index = i%52;
            }
            deck[i] = ((index/13)+1)*100 + index%13 + 2;//resets deck to starting order
          }
        
          shuffle(1, deck);// shuffles deck, does not actually input seed 1, just makes sure that seed != 0 so it shuffles
          for(int i = 0; i < 52; ++i){
            player[i] = 0;
            dealer[i] = 0; //resets player and deck hands 
          }
          firstdeal(deck, player, dealer);
          print_table(player, dealer, 0, money);
          play_game(deck, player, dealer, money);
          return;
}       
        else{
          printf("- $5\n");
          (*money) -= 5; 
        }
      }
      printf("Hit or stand? [h/s] "); // asks player what move to make 
      scanf(" %c", &move);
    }
    
    if(move == 'h'){
      player[player_index] = deck[deck_index]; // adds to player hand, adjusts indices for player and deck
      print_table(player, dealer, isplayerdone, money);
      --deck_index;
      ++player_index;
    }
    else if(move == 's'){  
      isplayerdone = true;//player's turn has ended, dealer hand will be revealed via an if/else in print_table
      print_table(player, dealer, isplayerdone, money);   // reprints table 
      
      if(score(dealer)>21){
        hit = false;
        sleep(2);
        printf("Dealer busts!\n");
      }
      else if(score(dealer)>= 17 || score(player)>21){// if player busts or dealer hit 17, stand, else dealer hit. 
        hit = false;            
        sleep(2);
        printf("Dealer stands.\n");               //final stand at the bottom of final table
      }
      else{
        sleep(2);
        printf("Dealer hits.\n");  // announces that dealer will hit below the table
        dealer[dealer_index] = deck[deck_index]; //changes dealer and player array to show the hit
        --deck_index; 
        ++dealer_index;
      }
    }
  }
  printf("\nFinal scores: Player %i, Dealer %i.\n", score(player), score(dealer)); //if higher score or dealer bust
  if((score(player)>score(dealer)&&(score(player)<=21)) || score(dealer)>21){
    (*money) += 20;
    printf("Player wins! +$20 Money: %i\n", *money);

  }
  else if(score(dealer)>score(player) || score(player)>21){ // if higher score or player bust, dealer win 
    printf("Dealer wins! Money: %i\n", *money);
  }
  else{
    printf("Push! Play again.\n");
    //re loop
    for(int i =0; i < 364; ++i){
      int index = i;
      if(i>=52){
        index = i%52;
      }
      deck[i] = ((index/13)+1)*100 + index%13 + 2;//resets deck to starting order
    }
    
    shuffle(1, deck);// shuffles deck, does not actually input seed 1, just makes sure that seed != 0 so it shuffles
    for(int i = 0; i < 52; ++i){
      player[i] = 0;
      dealer[i] = 0; //resets player and deck hands 
    }
    firstdeal(deck, player, dealer);
    print_table(player, dealer, 0, money);
    play_game(deck, player, dealer, money);
  }

}

void shuffle(int seed, int* deck){

  if(seed!=0){
    for(int i = 363; i>=0; --i){   //shuffles the deck if seed is not 0
      int j = rand() % (i+1);
      swap(i, j, deck);
    }
  }
}


int score(int* array){ // reads in a hand and returns the score
  int score = 0; 
  int i = 0;
  int ace = 0;
  while(array[i]!=0){
    if(array[i]%100 < 2){
      return 66; //error
    }
    else if(array[i]%100 < 11){
      score += array[i]%100;
    }
    else if(array[i]%100 < 14){
      score += 10;
    }
    else if(array[i]%100 == 14){ //if a hand has aces, they can count as 11 or 1,  default 11 but will revert to 1's
        score += 11;             // until hand is out of aces or under 21
        ++ace;
    }
    

    ++i;
  }
  if(score > 21 && ace){
    for(int i  = ace; score > 21 && i > 0; --i){
      score -= 10;
    }
  }

  return score;
}


