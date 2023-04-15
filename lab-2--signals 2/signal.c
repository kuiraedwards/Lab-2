// Worked with Keerthana Pullela and Jamarri White
// Kuira Edwards @02942519
/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmOn = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmOn = 1;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(2); //Schedule a SIGALRM for 1 second
  while(1) { //busy wait for signal to be delivered
    alarmOn = 0;
    alarm(2);
    while(!alarmOn) {
      printf("Turing was right!\n");
    }
  }
  return 0; //never reached
}