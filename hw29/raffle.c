/*raffle.c read in users, raffle tickets, read in winning ticket and declare
 * winners
 * Daniel Murray 234410*/

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char cstring[128];
typedef struct{    /*holds player name and an array of ticket numbers*/
  cstring name;
  int* arr_tickets;
} player;

int main(){
  int players;
  int win_tk;
  printf("How many people? ");
  scanf(" %d", &players);
  player arr_players[players];              /*reads in number of players and creates an array of structs for them*/
  for(int i = 0; i < players; ++i){         /*for loop creates heap arrays within the structs*/
    arr_players[i].arr_tickets = calloc(4, sizeof(int));
  }

  for(int i = 0; i < players; ++i){ /*for each player, prompts user for name and tickets*/
    cstring nm;
    printf("Person %i name: ", i+1);
    scanf(" %s", nm);
    strcpy(arr_players[i].name, nm);
    printf("Person %i tickets: ", i+1);
    for(int tk = 0; tk < 4; ++tk){
      int ticket;
      scanf(" %d", &ticket);
      arr_players[i].arr_tickets[tk] = ticket;
    }
  }
  
  printf("Winning ticket: "); /*prompts user for winning ticket, searches array for matches*/
  scanf(" %d", &win_tk);
  for(int i = 0; i < players; ++i){ /*loops thru all players*/
    bool winner = false;
    for(int tk = 0; tk < 4; ++tk){  /*loops thru each player's tickets*/
      if(arr_players[i].arr_tickets[tk] == win_tk){ /*if ticket number matches winning ticket, declares winner*/
        winner = true;
      }
    }
    if(winner){
      printf("%s won!\n", arr_players[i].name); /*prints depending on boolean to avoid printing multiple if
                                                  more than one winning ticket per player*/
    }
  }

  return 0;
}
