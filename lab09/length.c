/* length.c: list time between first and last episode of podcast in days, hours,
 * minutes, seconds 
 * Daniel Murray 234410
 */

#define _XOPEN_SOURCE
#include<time.h>
#include <stdio.h>
#include<stdbool.h>
#include "rss.h"

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

  // Declare strings to hold the info for each episode
  // Note, we expects titles and urls to (possibly) be very long,
  // but dates won't be as long.
  char date[64];

  while (next_episode(rss)) {
    // call functions from rss.h to get episode information
    episode_date(rss, date);
    printf("%s\n", date);
    struct tm date_struct = {0};
    strptime(date, "%a, %d %b %Y %H %M %S", &date_struct);
    time_t absolute_time = mktime(&date_struct);

    //find a way to read in two or compare to last, use difftime to compare the
    //times passede. 
    break;
  }

  // It's always good to clean up after yourself.
  close_rss(rss);

  return 0;
}
