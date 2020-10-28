/* Daniel Murray 234410 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

void selection_sort(int* data, int size);
bool before(int a, int b);
int oddneg(int a);

int main(){
  int* array = calloc(10, sizeof(int));
  for(int i = 0; i < 10; ++i){
    scanf(" %d", &array[i]);
  }
  
  selection_sort(array, 10);

  for(int i = 0; i < 10; ++i){
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

void selection_sort(int* data, int size){
  for (int i = 0; i < size - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < size; ++j) {
      if (before(data[j], data[nexti])) {
        nexti = j;
      }
    }
    // swap data[i] and data[nexti]
    int temp = data[i];
    data[i] = data[nexti];
    data[nexti] = temp;
  }
} 

bool before(int a, int b){
  a =  (oddneg(a));
  b = (oddneg(b));
  if(a<0&&b<0){
    return(a>b);
  }
  else{
    return(a < b);
  }
}

int oddneg(int a){
  if(a%2){
    a = -a;
  }
  return a;
}
