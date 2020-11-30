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
  time_t time;
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
void get_fastest(int waypoints, waypoint* arr_waypoints);



int main(){
  cstring filename;
  cstring command;
  int waypoints;
  printf("File: ");
  scanf(" %s", filename);
  FILE* fin = fopen(filename, "r"); //reads in filename and opens file to be read 
  fscanf(fin, " %d", &waypoints); 
  printf("Opened %s with %i waypoints\n", filename, waypoints);

  waypoint* arr_waypoints = calloc(waypoints, sizeof(waypoint));
  fill_waypoint(waypoints, arr_waypoints, fin); //reads in number of waypoints, creates array of structs, fills them

  while(true){  //reads in a command until quit is entered
    printf("command: ");
    scanf(" %s", command);
    if(strcmp(command, "quit")==0){
      break;
    }
    else if(strcmp(command, "stats")==0){ //time, distance, speed, pace 
      get_stats(waypoints, arr_waypoints); 
    }
    else if(strcmp(command, "landmarks")==0){ //closest distance to certain landmarks 
      get_landmark_distance(waypoints, arr_waypoints);
    }
    else if(strcmp(command, "fastest")==0){
      get_fastest(waypoints, arr_waypoints);
    }
  }
  
  free(arr_waypoints); //cleans up array and stream
  fclose(fin);
  return 0;
}

void fill_waypoint(int waypoints, waypoint* arr_waypoints, FILE* fin){
  for(int i = 0; i < waypoints; ++i){
    cstring date;
    cstring time;
    double latdeg;
    double londeg;
    struct tm time_holder = {0};
    fscanf(fin, " %lg", &latdeg);
    fscanf(fin, " %lg", &londeg);
    fscanf(fin, " %s", date);
    fscanf(fin, " %s", time);
    strptime(date, " %Y-%m-%d", &time_holder);
    strptime(time, " %T", &time_holder);
    arr_waypoints[i].time = mktime(&time_holder);
    arr_waypoints[i].gpsrad = make_gps(latdeg, londeg);
  }
}

void conv_seconds(int seconds, broketime* difference){ //converts int of seconds to fill broketime struct 
  difference->hours = seconds/3600;
  difference->minutes = (seconds%3600)/60;
  difference->seconds = ((seconds%3600)%60);
}
void get_stats(int waypoints, waypoint* arr_waypoints){
  double seconds_diff = 0;
  double distance = 0;
  for(int i =1; i < waypoints; ++i){
    seconds_diff += difftime(arr_waypoints[i].time, arr_waypoints[i-1].time);
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

void get_fastest(int waypoints, waypoint* arr_waypoints){
  double goal_distance; 
  int fast_time;
  scanf(" %lg", &goal_distance);
  bool first = true;
  double distance;
  int time;
  int wpnt;
  
  for(int i  = 1; i < waypoints; ++i){ //runs through multiple possible starting points 
    distance = 0;
    time = 0;
    wpnt = i;
    while(distance < goal_distance && wpnt < waypoints){ //runs to distance goal
      time += difftime(arr_waypoints[wpnt].time, arr_waypoints[wpnt-1].time);
      distance += gps_dist(arr_waypoints[wpnt].gpsrad, arr_waypoints[wpnt-1].gpsrad);
      ++wpnt;
    }
    if(distance >= goal_distance){ //if it is actually full distance 
      if(first){
        fast_time = time;
        first = false;
      }
      else if(time < fast_time){
        fast_time = time; 
      }
    } //full distance endif 
  } //forloop endif
  broketime fastest = {0};
  conv_seconds(fast_time, &fastest);
  if(fastest.hours){
    printf("%i hours, ",fastest.hours);
  }
  if(fastest.minutes){
    printf("%i minutes, ", fastest.minutes);
  }
  printf("%i seconds\n", fastest.seconds);
}
