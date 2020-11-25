/* recurlist.c: list.h implementation using recursion
 * Daniel Murray 234410 */

#include"list.h"

Node* add2front(char* s, Node* L){
  Node* temp = calloc(1, sizeof(Node));
  strcpy(temp->color, s); 
  temp->next = L;
  return temp;
}

void free_list(Node* L){
  if(L==NULL){
    return;
  }

  if(L->next){
    free_list(L->next);
  }
  free(L);
}

void print_fwd(Node* L){
  if(L==NULL){
    return;
  }
  printf("%s\n", L->color);
  if(L->next){
    print_fwd(L->next);
  }
}

bool contains(char* s, Node* L){
  if(L==NULL){
    return false;
  }
  bool have = false;
  if(L->next){
    have = contains(s, L->next);
  }
  if(strcmp(L->color, s)==0){
    have = true;
  }
  return have; 
}

char* get_ith(int i , Node* L){
  if(i>0){
    return get_ith(i-1, L->next);
  }
  else{
    return L->color;
  }
}

int num_chars(Node* L){  
  int count = 0;
  if(L==NULL){
    return count;
  }
  if(L->next){
    count += num_chars(L->next);
  }
  count += strlen(L->color);
  return count;
}

void print_rev(Node* L){
  if(L == NULL){
    return; 
  }
  else{
    print_rev(L->next);
    printf("%s\n", L->color);
  }
}

Node* remove_ith(int i, Node* L){
  if(L == NULL){
    return NULL;
  }
  else if(i==0){
    return L->next;
  }
  else{
    L->next = remove_ith(i-1, L->next);
    return L;
  }
}
