#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(){
  int id = getpid();
  int sTime;
  printf("I am the parent with pid:%d\n\n",getpid());
  fork();
  fork();
  int childid;
  if (getpid()!=id && getppid()==id ){
    childid=getpid();
  }
  if(getpid()==childid){
    printf("I am the child with pid:%d. My parent's pid is:%d\n",getpid(),getppid());
    int randFile = open("/dev/random", O_RDONLY);
    read(randFile, &sTime, sizeof(int));
    close(randFile);
    sTime = (abs(sTime) % 16) + 5;
    printf("Sleep time: %d\n", sTime);
    sleep(sTime);
    printf("I'm the child and I finished.\n");
  }
  if(getpid()=id){
    int *status;
    waitpid(childid(), status, 0);
    printf( " Child %d is finished. It slept for %d seconds.", childid(), sTime);
    printf( "Parent is done and program is ending.\n\n" );
  }
  
  return 0;
}
