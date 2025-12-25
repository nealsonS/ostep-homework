#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /*
  wait syscall returns the pid of the child process it's waiting for

  if wait is called in child,
  it'll basically wait or block, and return -1

   */

  const char *parent_text = "goodbye\n";
  const char *child_text = "hello\n";
  int rc = fork();
  if (rc < 0)
  {
    printf("fork failed!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    pid_t wait_res = wait(NULL);
    printf("wait_pid: %d\n", wait_res);
    printf("Is Child\nPID: %d\n", (int)getpid());
    printf("%s", child_text);
  }
  else
  {
    // pid_t wait_res = wait(NULL);
    // printf("wait_pid: %d\n", wait_res);
    printf("Is Parent\nPID: %d\n", (int)getpid());
    printf("%s", parent_text);
  }
}