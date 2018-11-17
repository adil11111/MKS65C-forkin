#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  int id = getpid();
  printf("I am the parent with pid:%d\n\n",getpid());
  fork();
  fork();
  int childid;
  if (getpid()!=id && getppid()==id ){
    childid=getpid();
  }
  if(getpid()==childid){
    printf("I am the child with pid:%d\nMy parent's pid is:%d\n",getpid(),getppid());
  }
  return 0;
}
