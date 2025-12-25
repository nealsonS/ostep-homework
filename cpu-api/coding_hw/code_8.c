#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /*
  bro this is actually just piping
  essentially make the stdout of child1 == write pipe
  and make stdin of child2 == read pipe

  remember to close the ends of the pipe we don't need
  to output a End-of-File signal
  to make it not hang

  man this was hard
   */
  int p[2];
  pipe(p);

  if (fork() == 0)
  {
    printf("child1. pid: %d\n", (int)getpid());
    // connect write end of pipe to stdout
    close(p[0]);
    dup2(p[1], STDOUT_FILENO);
    char *child1_out = "child1, STDOUT\n";
    write(STDOUT_FILENO, child1_out, strlen(child1_out));
    close(p[1]);
  }
  else
  {
    if (fork() == 0)
    {
      printf("child2. pid: %d\n", (int)getpid());
      // connect read end of pipe to stdin
      close(p[1]);
      dup2(p[0], STDIN_FILENO);

      char buff[100];
      read(STDIN_FILENO, buff, sizeof(buff));
      printf("%s", buff);
      close(p[0]);
    }
    else
    {
      waitpid(-1, NULL, 0);
      printf("parent pid: %d", (int)getpid());
    }
  }
}