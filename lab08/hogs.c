/* hogs.c: reports 10 IP addresses with most total data in connection
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
typedef struct{
  cstring name;
  int byte_size;
} IP;

bool before(IP a, IP b);
bool before_byte(IP a, IP b);   
int scan_distinct(IP* array, int size);
void selection_sort(IP* data, int size);
void selection_sort_byte(IP* data, int size);
void add_bytes(IP* array_IP, IP* total, int size, int distinct_IP);
void fill_IP(IP* array_IP, connection* array_connections, int size);

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

  IP* array_IP = calloc(2*connections, sizeof(IP)); /* creates array of structs [ name and byte use ] */
  fill_IP(array_IP, array_connections, connections); /*fills array_IP wit structs of address and byte usage */
  selection_sort(array_IP, 2*connections); //sorts the structs based on 'before' criteria (IP address)
  int distinct_IP = scan_distinct(array_IP, connections); /* sets number of unique IP addresses */
  
  IP* total = calloc(distinct_IP, sizeof(IP)); /* creates array of structs [ name and byte use ] */
  add_bytes(array_IP, total, 2*connections, distinct_IP); /*fills total with byte usage and name for each unique IP*/
  selection_sort_byte(total, distinct_IP); /*sorts total by byte usage*/

  for(int i = 0; i < 10; ++i){  /* prints out top 10 byte-using IP addresses */
    printf("%s\n", total[i].name); 
  }
  /* new plan, create an array the size of the entire file, all connections,
   * fill it with an address size pair, 2 for each connection, one outgoing one
   * incoming, sort based on IP addresses and counting unique ones, then make an adder function into a
   *new array with just the right amount of IP addresses counting totals */

  free(array_connections);
  free(total);                //free heap arrays 
  return 0;
}

void selection_sort(IP* data, int size){ //sorting function 
  for (int i = 0; i < size - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < size; ++j) {
      if (before(data[j], data[nexti])) {
        nexti = j;
      }
    }
    // swap data[i] and data[nexti]
    IP temp = data[i];
    data[i] = data[nexti];
    data[nexti] = temp;
  }
}

bool before(IP a, IP b){      //sorts connections by IP address
  return (strcmp(a.name, b.name)<0); 
}

int scan_distinct(IP* array, int size){ /*reads in IP addresses from array of structs, keeps track of how 
                                                  many unique IP addresses there are. Must be in order */
  int distinct_IP = 1;                     
  for(int i = 1; i < 2*size; ++i){
    if(strcmp(array[i].name, array[i-1].name)!=0){
      ++distinct_IP;
    }
  }
  return distinct_IP;
}

void fill_IP(IP* array_IP, connection* array_connections, int size){
  for(int i = 0; i < size; ++i){
    strcpy(array_IP[i].name, array_connections[i].source_IP);
    array_IP[i].byte_size = array_connections[i].byte_size;

    strcpy(array_IP[2*size-1-i].name, array_connections[i].destination_IP);
    array_IP[2*size-1-i].byte_size = array_connections[i].byte_size;
  }
}
/*IP addresses must be in order. Goes through array
of connections and copies each new IP address to 
an index in array_IP, adds byte usage to last IP
address in array_IP if no new IP scanned in */
void add_bytes(IP* array_IP, IP* total, int size, int distinct_IP){
  strcpy(total[0].name, array_IP[0].name); 
  total[0].byte_size = array_IP[0].byte_size;
  int i = 1;
  int IP = 0;
  while(i < size){
    if(strcmp(array_IP[i].name, array_IP[i-1].name)!=0){ /*if it is a new IP*/
          ++IP;
          strcpy(total[IP].name, array_IP[i].name);
          total[IP].byte_size = array_IP[i].byte_size;
    }
    else{
        total[IP].byte_size += array_IP[i].byte_size;
    }
    ++i;
  }
}

void selection_sort_byte(IP* data, int size){ /*sorts array indices by byte usage*/
 for (int i = 0; i < size - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < size; ++j) {
      if (before_byte(data[j], data[nexti])) {
        nexti = j;
      }
    }
    // swap data[i] and data[nexti]
    IP temp = data[i];
    data[i] = data[nexti];
    data[nexti] = temp;
  }
}

bool before_byte(IP a, IP b){      //sorts connections by byte usage
  return a.byte_size > b.byte_size;
}
