#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  int id = getpid();
  printf("I am the parent with pid:%d\n\n",getpid());
  fork();
  fork();
  if (getpid()!=id && getppid()==id ){
    printf("I am the child with pid:%d\nMy parent's pid is:\n",getpid(),getppid());
  }
  return 0;
}
