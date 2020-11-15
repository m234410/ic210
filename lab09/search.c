/* search.c: print out results with matching keyword  
 * Daniel Murray 234410
 */

#include <stdio.h>
#include "rss.h"
#include<stdbool.h>
#include<string.h>
void cap(char* s);
bool is_substring(char* title, char* keyword);

int main() {
  bool found_one = false;
  printf("RSS filename: ");
  fflush(stdout);
  char fname[128];
  scanf(" %s", fname);
  printf("Search for: "); 
  char keyword[128];
  scanf(" %s", keyword);

  // Notice, we call open_rss instead of fopen.
  RssFile* rss = open_rss(fname);
  if (!rss) {
    printf("ERROR: invalid rss file\n");
    return 1;
  }


  // Declare strings to hold the info for each episode
  // Note, we expects titles and urls to (possibly) be very long,
  // but dates won't be as long.
  char title[256];
  char url[256];

  // loop through the first 10 episodes using next_episode()
  while (next_episode(rss)) {
    // call functions from rss.h to get episode information
    episode_title(rss, title);
    episode_url(rss, url);
    
    //capitalize for easier comparison, save the old title to title_holder
    //before capitalization
    char title_holder[256];
    strcpy(title_holder, title);
    cap(title);
    cap(keyword);

    if(is_substring(title, keyword)){
  //title matches search word, print info
  // display the information we just looked up
      printf("title: %s\n", title_holder);
      printf("  url: %s\n", url);
      found_one = true;
    }
  }
  //print no matches found if there was never a hit on keyword
  if(!found_one){
    printf("No matches found\n");
  }

  // It's always good to clean up after yourself.
  close_rss(rss);

  return 0;
}

void cap(char* s){
  for(int i = 0; i<strlen(s); ++i){
    if(s[i] >= 'a' && s[i] <= 'z'){
      s[i] = s[i] - 'a' + 'A';
    }
  }
}
//searches title for keyword, returns bool 
bool is_substring(char* title, char* keyword){
  for(int i = 0; i < strlen(title); ++i){ 
    if(title[i] == keyword[0]){
      for(int j = 1; j < strlen(keyword); ++j){ 
        if(!(title[i+j] == keyword[j]))
          break;  
        else if(j == (strlen(keyword)-1))
          return true;
      }
    }
  }
  return false;
}
