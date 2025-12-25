#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /*
  we can make child go first by using wait(NULL) syscall on parent

  the other one idk lol
  */

  const char *parent_text = "goodbye\n";
  const char *child_text = "hello\n";

  int fd = open("text_3.txt", O_CREAT | O_WRONLY, 0644);

  int rc = fork();
  if (rc < 0)
  {
    printf("fork failed!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Is Child\nPID: %d\n", (int)getpid());
    printf("%s", child_text);
    close(fd);
  }
  else
  {
    // wait(NULL);
    printf("Is Parent\nPID: %d\n", (int)getpid());
    printf("%s", parent_text);
    write(fd, "test", strlen("test"));
  }
}