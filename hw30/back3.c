/* Daniel Murray back3: read in numbers until a negative number is entered,
 * output third to last number*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct Node Node;
struct Node{
  int num;
  Node* next;
};
Node* add2front(int val, Node* oldlist);

int main(){
  Node* start = calloc(1, sizeof(Node));
  int number; 
  bool positive = true; 
  

  while(positive){
    scanf(" %d", &number);
    if(number>=0){
      start = add2front(number, start);
    }
    else if(number<0){
      positive = false;
    }
  }

    
  printf("%i\n", start->next->next->num);


  return 0;
}

Node* add2front(int val, Node* oldlist){
  Node* temp = calloc(1, sizeof(Node));
  temp->num = val; 
  temp->next = oldlist;
  return temp;
}
