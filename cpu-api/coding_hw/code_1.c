#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
/*
Answer:
When accessing variable on parent and child,
and manipulating it
both results in the same 
value of x

Each parent and child has its own copy of the variable
*/

  int x = 100;
  x += 1;
  int rc = fork();
  x += 1;

  if(rc < 0 ) { // fork failed
    printf("fork failed\n");
    exit(1);
  } else if (rc == 0){ // child process
    printf("Is Child\nPID: %d", (int) getpid());
    printf("value of x: %d\n", x);
  } else {
    printf("Is parent\nPID: %d", (int) getpid());
    printf("value of x: %d\n", x);
  }
}