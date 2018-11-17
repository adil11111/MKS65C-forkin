#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(){
  int id = getpid();
  printf("I am the parent with pid:%d\n\n",id);
  int a = fork();
  if (a!=0)
    a = fork();
  if(a==0){
    printf("I am the child with pid:%d. My parent's pid is:%d.",getpid(),getppid());
    int randFile = open("/dev/random", O_RDONLY);
    int sTime;
    read(randFile, &sTime, sizeof(int));
    close(randFile);
    sTime = (abs(sTime) % 16) + 5;
    printf("I'm going to sleep for: %d seconds.\n", sTime);
    sleep(sTime);
    printf("\nI'm the child and I finished.\n");
    return sTime;
  }
  if(a!=0){
    int status;
    int cid=wait(&status);
    if(WIFEXITED(status)) {
            int sec = WEXITSTATUS(status);
	    printf( "I am the parent and my child %d is finished. It slept for %d seconds.\n", cid, sec);		
        }
    printf( "Parent is done and program ending.\n\n" );
  } 
  return 0;
}
