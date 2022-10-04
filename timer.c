/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmFlag = 0;
int numAlarm = 0;

time_t start, stop;

void handlesAlarm(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmFlag = 1;
  numAlarm++;
}

void handleSigint(int signum){
  int timeTotal;
  stop = time(NULL);
  timeTotal = stop - start;
  if(timeTotal > 30){
    exit(1);
  }
  printf("The number of alarms is %d\n", timeTotal);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handlesAlarm); //register handler to handle SIGALRM
  signal(SIGINT, handleSigint);
  start = time(NULL);
  int count = 0;
  while(1){
    alarmFlag = 0;
    alarm(2);
    while(!alarmFlag);
      printf("Turing was right!\n");
      alarmFlag = 1;
    count++; 
    if(count > 15){
      exit(1);
    }
  }
  return 0;
}