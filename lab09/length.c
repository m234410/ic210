/* length.c: list time between first and last episode of podcast in days, hours,
 * minutes, seconds 
 * Daniel Murray 234410
 */

#define _XOPEN_SOURCE
#include<time.h>
#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include "rss.h"
typedef struct{
  int days;
  int hours;
  int minutes;
  int seconds;
} broketime;

time_t give_time(char* date);
void conv_seconds(int seconds, broketime* difference);

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

  
  char old_date[64];
  char new_date[64];
  char date[64];
  int seconds_diff = 0;
  
  //reads in first date simultaneously as oldest and newest podcast
  next_episode(rss);
  episode_date(rss, date);
  time_t absolute_time_new_date = give_time(date);
  time_t absolute_time_old_date = give_time(date);

     //if the date is newer, it will become new_date, if it is older, it will
    //become old_date
  while (next_episode(rss)) {
    episode_date(rss, date);
    time_t absolute_time_date = give_time(date);
    if(absolute_time_date < absolute_time_old_date){
      strcpy(old_date, date);
      absolute_time_old_date = give_time(old_date);
      seconds_diff = difftime(absolute_time_new_date, absolute_time_old_date); 
    }
    else if(absolute_time_date > absolute_time_new_date){
      strcpy(new_date, date);
      absolute_time_new_date = give_time(new_date);
      seconds_diff = difftime(absolute_time_new_date, absolute_time_old_date); 
    }
  }
  //creates struct to be filled by convert function, converts seconds of time
  //difference to days, hours, minutes, seconds
  broketime diff = {0};
  conv_seconds(seconds_diff, &diff);
  printf("%d days %d hours %d minutes %d seconds\n", diff.days, diff.hours, diff.minutes, diff.seconds);

  // It's always good to clean up after yourself.
  close_rss(rss);

  return 0;
}

void conv_seconds(int seconds, broketime* difference){
  difference->days = seconds/86400;
  difference->hours = (seconds%86400)/3600;
  difference->minutes = ((seconds%86400)%3600)/60;
  difference->seconds = (((seconds%86400)%3600)%60);
}

time_t give_time(char* date){
  struct tm date_struct= {0};
  strptime(date, "%a, %d %b %Y %H:%M:%S", &date_struct);
  time_t absolute_time_date = mktime(&date_struct);
  return absolute_time_date;
}
