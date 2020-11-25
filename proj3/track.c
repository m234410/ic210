/* track.c: GPS tracks program main program
 * Daniel Murray 234410*/

#define _XOPEN_SOURCE
#include<time.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"gps.h"

typedef char cstring[128];
typedef struct{
  struct tm time;
  gpsco gpsrad;
} waypoint;

typedef struct{
  int hours;
  int minutes;
  int seconds;
} broketime;

typedef struct{
  cstring name; 
  gpsco gpsrad;
  double dist;
} landmark;

void conv_seconds(int seconds, broketime* difference);
void fill_waypoint(int waypoints,waypoint* arr_waypoints, FILE* fin);
void get_stats(int waypoints, waypoint* arr_waypoints);
void get_landmark_distance(int waypoints, waypoint* arr_waypoints);
void fill_landmark(int landmarks, landmark* arr_landmarks, FILE* fin);
void selection_sort_landmark(landmark* arr_landmarks, int landmarks);
bool before(landmark a, landmark b);



int main(){
  cstring filename;
  cstring command;
  int waypoints;
  printf("File: ");
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r");
  fscanf(fin, " %d", &waypoints);
  printf("Opened %s with %i waypoints\n", filename, waypoints);

  waypoint* arr_waypoints = calloc(waypoints, sizeof(waypoint));
  fill_waypoint(waypoints, arr_waypoints, fin);

  while(true){
    printf("command: ");
    scanf(" %s", command);
    if(strcmp(command, "quit")==0){
      break;
    }
    else if(strcmp(command, "stats")==0){
      get_stats(waypoints, arr_waypoints); 
    }
    else if(strcmp(command, "landmarks")==0){
      get_landmark_distance(waypoints, arr_waypoints);
    }
  }
  
  free(arr_waypoints);
  fclose(fin);
  return 0;
}

void fill_waypoint(int waypoints, waypoint* arr_waypoints, FILE* fin){
  for(int i = 0; i < waypoints; ++i){
    cstring date;
    cstring time;
    double latdeg;
    double londeg;
    fscanf(fin, " %lg", &latdeg);
    fscanf(fin, " %lg", &londeg);
    fscanf(fin, " %s", date);
    fscanf(fin, " %s", time);
    strptime(date, " %Y-%m-%d", &arr_waypoints[i].time);
    strptime(time, " %T", &arr_waypoints[i].time);
    arr_waypoints[i].gpsrad = make_gps(latdeg, londeg);
  }
}

void conv_seconds(int seconds, broketime* difference){
  difference->hours = seconds/3600;
  difference->minutes = (seconds%3600)/60;
  difference->seconds = ((seconds%3600)%60);
}
void get_stats(int waypoints, waypoint* arr_waypoints){
  double seconds_diff = 0;
  double distance = 0;
  for(int i =1; i < waypoints; ++i){
    seconds_diff += difftime(mktime(&arr_waypoints[i].time), mktime(&arr_waypoints[i-1].time));
    distance += gps_dist(arr_waypoints[i].gpsrad, arr_waypoints[i-1].gpsrad);
  }
  broketime total_time = {0};
  conv_seconds(seconds_diff, &total_time); 
  printf("Total time: ");
  if(total_time.hours){
    printf("%i hours, ",total_time.hours);
  }
  printf("%i minutes, %i seconds\n", total_time.minutes, total_time.seconds);
  printf("Total distance: %g miles\n", distance);
  
  double sec_per_hour = 3600;
  double mph = distance/(seconds_diff/sec_per_hour);
  printf("Average speed: %g mph\n", mph);

  double pace_seconds = seconds_diff/distance;
  int pace_minutes = pace_seconds/60;
  pace_seconds = pace_seconds - pace_minutes*60;
  printf("Average pace: %i minutes, %g seconds per mile\n", pace_minutes, pace_seconds);
}

void fill_landmark(int landmarks, landmark* arr_landmarks, FILE* fin){
  for(int i = 0; i < landmarks; ++i){
    double latdeg;
    double londeg;
    fscanf(fin, " %lg", &latdeg);
    fscanf(fin, " %lg", &londeg);
    arr_landmarks[i].gpsrad = make_gps(latdeg, londeg);
    fscanf(fin, "%s", arr_landmarks[i].name);
  }
}

void selection_sort_landmark(landmark* arr_landmarks, int landmarks) {
  for (int i = 0; i < landmarks - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < landmarks; ++j) {
      if (before(arr_landmarks[j], arr_landmarks[nexti])) {
        nexti = j;
      }
    }
    // swap arr_landmarks[i] and arr_landmarks[nexti]
    landmark temp = arr_landmarks[i];
    arr_landmarks[i] = arr_landmarks[nexti];
    arr_landmarks[nexti] = temp;
  }
}

bool before(landmark a, landmark b){
  return a.dist<b.dist;
}

void get_landmark_distance(int waypoints, waypoint* arr_waypoints){
  cstring filename; 
  int landmarks;
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r");
  fscanf(fin, " %d", &landmarks);
  landmark* arr_landmarks = calloc(landmarks, sizeof(landmark));
  fill_landmark(landmarks, arr_landmarks, fin);

  for(int lndmk = 0; lndmk < landmarks; ++lndmk){
    double shortest_dist = gps_dist(arr_waypoints[0].gpsrad, arr_landmarks[lndmk].gpsrad); 
    for(int i = 1; i < waypoints; ++i){
      if(gps_dist(arr_waypoints[i].gpsrad, arr_landmarks[lndmk].gpsrad) < shortest_dist){
        shortest_dist = gps_dist(arr_waypoints[i].gpsrad, arr_landmarks[lndmk].gpsrad);
      }
    }
    arr_landmarks[lndmk].dist = shortest_dist;
  }
  
  selection_sort_landmark(arr_landmarks, landmarks);
  for(int i = 0; i < landmarks; ++i){
    printf("%s %g miles\n", arr_landmarks[i].name, arr_landmarks[i].dist);
  }

  fclose(fin);
}

//fastest, run through adding (while loop) times and distances until reaching that distance 
//at least, do this through the entire list (for), checking for shorter times (outside for loop)
