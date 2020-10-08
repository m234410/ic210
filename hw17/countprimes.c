/* Daniel Murray 234410
 */

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
typedef char cstring[128];

bool isprime(int n);
int getnum(int atleast);
int countprimes(int a, int b);

int main(){

  int atleast = 1;
  atleast = getnum(atleast);
  int a = atleast;
  int b = getnum(atleast);
  int count = 0; 
  printf("There are %i primes between %i and %i.\n", countprimes(a, b), a, b);

  return 0;

}

bool isprime(int n){
  if (n < 2) {
    return false;
  }

  for (int fact=2; fact*fact <= n; ++fact) {
    if (n % fact == 0) {
      return false;
    }
  }
  return true;
}

int getnum(int atleast){
  int entry = 0;
  printf("Enter a number at least %i: ", atleast);
  scanf(" %d", &entry);
  if(entry<atleast){
    printf("Too small!\n");
    getnum(atleast);
  }
  
  else{
    return entry;
  }
}

int countprimes(int a, int b){
  int count = 0;
  count += isprime(a);
  if(a!=b){
    count += countprimes(a+1, b);
  } 
    return count;
}
