/* Daniel Murray 234410: wordstart: reads in a string of words until END, reads
 * in a letter, prints out words starting with that letter*/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
typedef char cstring[128];
typedef struct Node Node; 
struct Node{
  cstring word; 
  Node* next; 
};
Node* add_word(char* data, Node* L);
void search_letter(Node* L, char letter);

int main(){
  printf("Enter words followed by END:\n"); /*reads words in and adds them to linked list until "END" is read in*/
  Node* start = calloc(1, sizeof(Node));
  cstring read_in;
  while(strcmp(read_in, "END")!=0){
    scanf(" %s", read_in);
    start = add_word(read_in, start);
  }

  printf("What letter? ");
  char letter;
  scanf(" %c", &letter);
  search_letter(start, letter);

  



  return 0;
}

Node* add_word(char* data, Node* L){
  Node* temp = calloc(1, sizeof(Node));
  strcpy(temp->word, data);
  temp->next = L;
  return temp;
}

void search_letter(Node* L, char letter){
  if(L == NULL){
    return;
  }
  else{
    if(L->word[0] == letter){
      printf("%s\n", L->word);
    }
    search_letter(L->next, letter);
  }
}
