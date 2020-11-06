/* distinct.c: Printing the number of different protocols
 *  Daniel Murray 234410 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef char cstring[128];
typedef struct{
  int ID;
  double capture_time; 
  cstring source_IP;
  cstring destination_IP;
  cstring protocol; 
  int byte_size;
} connection;


bool before(connection a, connection b);
void selection_sort(connection* data, int size);
int scan_distinct(connection* array, int size);

int main(){
  cstring file;
  int connections;
  printf("What file? ");
  scanf(" %s", file);
  FILE* fin = fopen(file, "r"); //reads name of file and opens stream

  fscanf(fin, " %d", &connections); //reads number of connections then scans all info to an array of structs
  connection* array_connections = calloc(connections, sizeof(connection));
  for(int i = 0; i < connections; ++i){
    fscanf(fin, " %d %lg %s %s %s %d\n", &array_connections[i].ID, &array_connections[i].capture_time, array_connections[i].source_IP, array_connections[i].destination_IP, array_connections[i].protocol, &array_connections[i].byte_size);
  }

  selection_sort(array_connections, connections); //sorts the structs based on 'before' criteria 

  printf("%i\n", scan_distinct(array_connections, connections)); //prints number of distinct functions

  free(array_connections); //free heap array 

  return 0;
}

void selection_sort(connection* data, int size){ //sorting function 
  for (int i = 0; i < size - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < size; ++j) {
      if (before(data[j], data[nexti])) {
        nexti = j;
      }
    }
    // swap data[i] and data[nexti]
    connection temp = data[i];
    data[i] = data[nexti];
    data[nexti] = temp;
  }
}

bool before(connection a, connection b){      //sorts connections by protocol alphabetical order
  return (strcmp(a.protocol, b.protocol)<0); 
}

int scan_distinct(connection* array, int size){ //reads in protocols from array of structs, for each new one, add
  int distinct_functions = 1;                   // one to the count, only works if alphabetical order
  for(int i = 1; i < size; ++i){
    if(strcmp(array[i].protocol, array[i-1].protocol)!=0){
      ++distinct_functions;
    }
  }
  return distinct_functions;
}
