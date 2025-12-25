#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /*
  using execvp, we can get a NULL terminated array of chars
  to replace the forked process with a new code

  there are many different types of exec in C
  to accommodate for different type of inputs/parameters
  and whether using PATH or

  execl makes you type the parameters one by one and end with a NULL
  while execv uses a pointer to a array of char pointers with NULL at the end

  execv vs execvp basically finds in the PATH so instead of typing
  /bin/ls, you can use ls
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
    char *myargs[3];
    myargs[0] = strdup("/bin/ls");
    myargs[1] = strdup(".");
    myargs[2] = NULL;

    execvp(myargs[0], myargs);

    printf("Is Child\nPID: %d\n", (int)getpid());
    printf("%s", child_text);
  }
  else
  {
    // wait(NULL);
    printf("Is Parent\nPID: %d\n", (int)getpid());
    printf("%s", parent_text);
  }
}