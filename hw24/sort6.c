/*Daniel Murray*/

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>


void selection_sort(int* data, int size);
bool before(int a, int b);

int main(){
  int* array = calloc(6, sizeof(int));
  printf("Enter 6 numbers: ");
  for(int i = 0; i < 6; ++i){
    scanf(" %d", &array[i]);
  }

  selection_sort(array, 6);

  for(int i = 0; i < 6; ++i){
    printf("%i\n", array[i]);
  }

  free(array);
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
  if (a > b) {
    return true;
  } else {
    return false;
  }
}
