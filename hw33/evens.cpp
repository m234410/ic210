/* Daniel Murray 234410: even numbers homework*/

#include<cstdio>
#include<cstring>
using namespace std; 

int* readnums(int& size);
bool isEven(int x); 

int main(){
  int n; 
  int* array = readnums(n); 

  int count = 0;
  for(int i = 0; i < n; ++i){
    if(isEven(array[i])){
      ++count; 
    }
  }

  printf("%d even numbers\n", count);

  delete [] array; //free array
  return 0;
}

int* readnums(int& size){
  printf("How many numbers? ");
  scanf(" %d", &size);

  int* arr = new int[size];
  for(int i = 0; i < size; ++i){
    scanf(" %d", &arr[i]);
  }

  return arr; 
}

bool isEven(int x){
  if(x%2==0){
    return true;
  }
  else{
    return false;
  }
}
