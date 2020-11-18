/*Daniel Murray 234410: duration.c: reads in RSS file, asks for desired
 * duration, finds episode whose length is closest in duration without going
 * over */
#define _XOPEN_SOURCE
#include<time.h>
#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include "rss.h"
typedef char cstring[256];
void episode_duration(RssFile* rfile, char* s);
void parse_time(char * time, int type, struct tm *output);
int format(char* time);
int seconds(char* time);

int main() {
  printf("RSS filename: ");
  fflush(stdout);
  char fname[128];
  scanf(" %s", fname);

  // Notice, we call open_rss instead of fopen.
  RssFile* rss = open_rss(fname);
  if (!rss) {
    printf("ERROR: invalid rss file\n");
    return 1;
  }

  // reads in desired time duration 
  cstring desired_duration;
  cstring current_duration;
  printf("Desired duration: ");
  scanf(" %s", desired_duration);
  int goal = seconds(desired_duration);
  int closest;
  bool got_one = false;
  cstring url;
  cstring duration;
  cstring title;

  //looks for at least one duration that is less than the goal time
  while(next_episode(rss)){
    episode_duration(rss, current_duration);
    int compare = seconds(current_duration);
    if(compare<=goal){
      closest = compare;
      episode_title(rss, title);
      episode_url(rss, url);
      strcpy(duration, current_duration);
      got_one = true;
      break;
    }
  }
  

  //runs on an if loop after the closest has been set, finds duration less than
  //but closest to the goal
  if(got_one){
    while (next_episode(rss)) {
      episode_duration(rss, current_duration);
      int compare = seconds(current_duration);
      if(compare<=goal && (goal-compare)<(goal-closest)){ //closer to goal than closest) 
        closest = compare;
        episode_title(rss, title);
        episode_url(rss, url);
        strcpy(duration, current_duration);
      }
    }
  }
  
  //prints the results 
  if(!got_one){
    printf("No shorter episodes found\n");
  }
  else{
    printf("title: %s\n  url: %s\n%d seconds shorter\n", title, url, goal-closest);
  }

  return 0;
}

//copies a string to s telling the duration of the podcast
void episode_duration(RssFile* rfile, char* s) {
  if (!rfile || !rfile->current_item) {
    fprintf(stderr, "ERROR in call to episode_date: did you call next_episode() first?\n");
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  while (item_child) {
    if (strcmp((char*)item_child->name, "duration") == 0) {
      strcpy(s, (char*)item_child->children->content);
      return;
    }
    item_child = item_child->next;
  }

  // no duration found within the item
  // better to use a default date than make an error
  strcpy(s, "9:99");
}

//converts a string in H:M:S, M:S, or S format into an int of seconds
int seconds(char* time){
  int type = format(time);
  struct tm time_struct= {0};
  parse_time(time, type, &time_struct);
  
  int time_seconds = time_struct.tm_sec + time_struct.tm_min*60 + time_struct.tm_hour*3600;
  return time_seconds;
}

//determines what format a given string is
int format(char* time) {
  int colon = 0;
  for(int i = 0; i < strlen(time); ++i) {
    if(time[i]==':') {
      ++colon;
    }
  }
  if(colon==2) { //H:M:S format
    return 2;
  }
  else if(colon==1) { //M:S format
    return 1;
  }
  else if(colon==0) { //S format
    return 0; 
  }
  return 999; //error
}

//wacked out function that reads in a string of one of three types and gives the
//output to seconds function, output would be tm struct filled with hours,
//minutes, seconds
void parse_time(char * time, int type, struct tm *output){
  int size = strlen(time)-1;
  if(type==2) {
    output->tm_sec += time[size]-'0';
    output->tm_sec += 10*(time[size-1]-'0');
    output->tm_min += time[size-3]-'0';
    output->tm_min += 10*(time[size-4]-'0');
    output->tm_hour += time[size-6]-'0';
    if(size>=7){
    output->tm_hour += 10*(time[size-7]-'0');
    }
  }
  else if(type==1) {
    output->tm_sec += time[size]-'0';
    output->tm_sec += 10*(time[size-1]-'0');
    output->tm_min += time[size-3]-'0';
    if(size>=4){
    output->tm_min += 10*(time[size-4]-'0');
    }
  }
  else if(type==0) {
    for(int i = size; i >= 0; --i){
    output->tm_sec += pow(10, size-i)*(time[i]-'0');
    }
  }
}
