// Worked with Keerthana Pullela and Jamarri White
// Kuira Edwards @02942519

/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmOn = 0;
int num = 0;

time_t start, stop;

void handler(int signum) { //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmOn = 1;
  num++;
}

void sigHandler(int signum) {
  int total;
  stop = time(NULL);
  total = stop - start;

  printf("The number of alarms is %d\n", total);
}

int main(int argc, char *argv[]) {
  signal(SIGALRM, handler); //handles SIGALRM
  signal(SIGINT, sigHandler);
  start = time(NULL);
  while(1) {
    alarmOn = 0;
    alarm(2);
    while(!alarmOn) {
      printf("Turing was right!\n");
    }
  }
  return 0;
}