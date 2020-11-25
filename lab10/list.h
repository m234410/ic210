/* linked list header file
 * Daniel Murray 234410: list.h 
 */
 
#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "list.h"
#include<string.h>
typedef char cstring[128];
typedef struct Node Node;
struct Node{
  cstring color;
  Node* next;
};

Node* add2front(char* s, Node* L);
void print_fwd(Node* L);
void free_list(Node* L);
bool contains(char* s, Node* L);
char* get_ith(int i, Node* L);
int num_chars(Node* L);
void print_rev(Node* L); 
Node* remove_ith(int i, Node* L);

#endif //DRAW_H
