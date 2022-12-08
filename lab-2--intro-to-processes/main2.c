#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int i;

     for(i=0; i<2; i++) {
          pid = fork();
          if (pid == 0) 
               ChildProcess();
          else if(pid < 0)
               printf("Fork Error! \n");
     }
     ParentProcess();
}

void  ChildProcess(void)
{
     int   i;
     int MAX_COUNT;
     int random;
     srand(getpid());
     MAX_COUNT = (rand() % 25) +1;

     for (i = 0; i <= MAX_COUNT; i++) {
          printf("Child Pid: %d is going to sleep!\n", getpid());
          random = rand() % 10;
          sleep(random + 1);
     printf("Child Pid: %d is awake!\n Let's find the Parent: %d!\n", getpid(), getpid());
}
     exit(0);
}

void  ParentProcess(void)
{
     int   i;
     int status;
     int cpid;

     for (i = 0; i <= 2; i++) {
          cpid = wait(&status);
          printf("Child Pid: %d has completed\n", cpid);
}
}