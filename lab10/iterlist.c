/* iterlist.c: list.h implementation using loops
 * Daniel Murray
 */

#include"list.h"

Node* add2front(char* s, Node* L){
  Node* temp = calloc(1, sizeof(Node));
  strcpy(temp->color, s); 
  temp->next = L;
  return temp;
}

void free_list(Node* L){
  while (L) {
    struct Node* temp = L->next;
    free(L);
    L = temp;
  }
}

void print_fwd(Node* L){
  for(Node* cur = L; cur; cur=cur->next){
    printf("%s\n", cur->color);
  }
}

bool contains(char* s, Node* L){
  for(Node* cur = L; cur; cur = cur->next){
    if(strcmp(cur->color, s)==0){
      return true;
    }
  }
  return false;
}
 
char* get_ith(int i, Node* L){
  Node* temp = L;
  for(int j = 0; j < i; ++j){
    temp = temp->next;
  }
  return temp->color;
}

int num_chars(Node* L){
  int count = 0;
  for(Node* cur = L; cur; cur = cur->next){
    count += strlen(cur->color);
  }
  return count;
}

void print_rev(Node* L){
  int i  = -1;
  for(Node* cur = L; cur; cur = cur->next){
    ++i;
  }
  while(i>=0){
    Node* temp = L;
    for(int j = i; j>0; --j){
      temp = temp->next;
    }
    --i;
    printf("%s\n", temp->color);
  }
}

Node* remove_ith(int i, Node* L){
  Node* temp = L;
  if(i==0){
    temp = temp->next;
    return temp;
  }
  --i;
  for(i; i > 0; --i){
    temp = temp->next;
  }
  temp->next=temp->next->next;
  return L;
}

