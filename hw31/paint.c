/* Daniel Murray 234410: paint.c: adds or strips layers of paint, quits when
 * stripping a blank canvas*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef char cstring[128];
typedef struct Node Node;
struct Node{
  cstring color;
  Node* next;
}; 
Node* paint(char* color, Node* old_head);
Node* strip(Node* old_head);
void check_paint(Node* layer);

int main(){
  Node* start = calloc(1, sizeof(Node));
  strcpy(start->color, "blank");
  start->next = NULL;
  while(true){
    check_paint(start);
    cstring action;
    scanf(" %s", action);
    if(strcmp(action, "paint")==0){
      cstring color;
      scanf(" %s", color);
      start = paint(color, start);
    }
    else if(strcmp(action, "strip")==0){
      start = strip(start);
    }
  }
  

  return 0;
}

Node* paint(char* color, Node* old_head){
  Node* temp = calloc(1, sizeof(Node));
  strcpy(temp->color, color);
  temp->next = old_head;
  return temp; 
}

Node* strip(Node* old_head){
  Node* temp = old_head->next;
  free(old_head);
  if(temp==NULL){
    exit(0);
  }
  return temp;
}

void check_paint(Node* layer){
  if(strcmp(layer->color, "blank")==0){
    printf("The canvas is blank.\n");
  }
  else{
    printf("The top color is %s.\n", layer->color);
  }
}
