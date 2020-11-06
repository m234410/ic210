/* large.c: Printing the 10 smallest connections
 * (Note, write large.c first and then copy it to this file with
 * one minor change!)
 *Daniel Murray 234410 - print out 10 smallest connections in descending order*/

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

  selection_sort(array_connections, connections); 

  for(int i = 0; i < 10; ++i){
    printf("%i\n", array_connections[i].byte_size);
  }

  free(array_connections);

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

bool before(connection a, connection b){
  return a.byte_size < b.byte_size; 
}

