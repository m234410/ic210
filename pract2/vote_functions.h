/* Daniel Murray 234410*/
#ifndef VOTE_FUNCTIONS_H
#define VOTE_FUNCTIONS_H
#include<stdbool.h>
typedef char cstring[128];

void get_names(cstring candidate1, cstring candidate2);
bool update_counts(cstring selection, cstring candidate1, int* count1, cstring candidate2, int* count2);
void display_results(cstring candidate1, int count1, cstring candidate2, int count2);

#endif

