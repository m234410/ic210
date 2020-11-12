/* Daniel Murray 234410 read in player names and scores, print out names
 * alphabetically with high score */

#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdio.h>
typedef char cstring[128];
typedef struct{
  cstring f_name; 
  cstring l_name;
  int score; 
} player; 
void get_topscore(player* arr_player, player* arr_topscore, int size);
void selection_sort(player* data, int size);
bool before(player a, player b);

int main(){
  cstring filename; 
  int size;
  int j = 0;

  printf("filename: ");
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r");  /*reads in file name and opens fin read stream*/

  fscanf(fin, " %d", &size);               /*scans in size, creates array of structs, fills them*/
  player* arr_player = calloc(size, sizeof(player));
  for(int i = 0; i < size; ++i){
    fscanf(fin, " %s %s %d", arr_player[i].f_name, arr_player[i].l_name, &arr_player[i].score);  
  }

  player* arr_topscore = calloc(size, sizeof(player)); /* creates new array for topscores */
  selection_sort(arr_player, size); /* alphabetizes array */
  get_topscore(arr_player, arr_topscore, size); /* transfers to new array taking only top scores */

  while(arr_topscore[j].score!=0 && j < size){ /* prints names and scores of array */
    printf("%s %s %i\n", arr_topscore[j].f_name, arr_topscore[j].l_name, arr_topscore[j].score);
    ++j;
  }

  free(arr_topscore);
  free(arr_player);
  return 0;
}
//DEFINITIONS//
void selection_sort(player* data, int size) { /*alphabetize based on "before" criteria */
  for (int i = 0; i < size - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < size; ++j) {
      if (before(data[j], data[nexti])) {
        nexti = j;
      }
    }
    // swap data[i] and data[nexti]
    player temp = data[i];
    data[i] = data[nexti];
    data[nexti] = temp;
  }
}

bool before(player a, player b){ /* alphabetizes, prioritizing last name, but comparing first if same last */
  if(strcmp(a.l_name, b.l_name) == 0){
    return (strcmp(a.f_name, b.f_name) < 0);
  }
  return (strcmp(a.l_name, b.l_name) < 0);
}

void get_topscore(player* arr_player, player* arr_topscore, int size){
  int index = 0;
  arr_topscore[0] = arr_player[0];
  
  for(int i = 1; i < size; ++i){
    if(strcmp(arr_player[i].f_name, arr_player[i-1].f_name)==0 && strcmp(arr_player[i].l_name, arr_player[i-1].l_name)==0){ /*names are the same: check to see if score is higher, replace if it is, else do nothing*/
      if(arr_player[i].score > arr_topscore[index].score){
        arr_topscore[index].score = arr_player[i].score;
      }
    }
    else{
      ++index;
      strcpy(arr_topscore[index].f_name, arr_player[i].f_name); /*new name: add to index to make next entry, copy */
      strcpy(arr_topscore[index].l_name, arr_player[i].l_name); /*first and last to topscore array, make this score*/
      arr_topscore[index].score = arr_player[i].score;                           /*topscore for this index */
    }
  }
}
