#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /*
  after closing STDOUT_FILENO in the child process
  bro, the stdoutput is gone for the child process
  there isn't any output anymore
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
    close(STDOUT_FILENO);
    printf("Is Child\nPID: %d\n", (int)getpid());
    printf("%s", child_text);
  }
  else
  {
    pid_t wait_res = waitpid(0, NULL, WUNTRACED);
    printf("wait_pid: %d\n", wait_res);
    printf("Is Parent\nPID: %d\n", (int)getpid());
    printf("%s", parent_text);
  }
}