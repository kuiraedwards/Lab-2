/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

//****

int hand;
int count;
time_t startTime, endTime;

void handler(int signum) { //signal handler
  count += 1;
  printf("Hello World!\n")
  hand = 1;
  exit(1); //exit after printing
}

void timerhandler(int signum) { //time tracker
  time_t runTime;
  endTime = time(NULL);
  runTime = endTime - startTime;
  printf("\nNumber of alarms %d\nNumber of seconds executed %d seconds\n", count, (int)runTime);
  exit(0);
}

int main(int argc, char * argv[])
{
  startTime = time(NULL);
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, timerhandler);
  while(1) { //busy wait for signal to be delivered
    hand = 0;
    alarm(1); //Schedule a SIGALRM for 1 second
  while(hand == 0);
  printf("Turing was right!\n") 
  }
  //busy wait for signal to be delivered
  return 0; //never reached
}

*******/