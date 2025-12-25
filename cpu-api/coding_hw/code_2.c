#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /*
  When writing at the same time,
  it works, but parent goes first i guess
  I don't know why



  */

  const char parent_text[] = "parent";
  size_t parent_len = strlen(parent_text);

  const char child_text[] = "parent";
  size_t child_len = strlen(child_text);

  int fd = open("./text_3.txt", O_APPEND | O_WRONLY, 0644);

  int rc = fork();
  if (rc < 0)
  {
    printf("fork failed!\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Is Child\nPID: %d\n", (int)getpid());
    printf("fd: %d\n", fd);

    write(fd, "child", strlen("child"));
  }
  else
  {
    printf("Is Parent\nPID: %d\n", (int)getpid());
    printf("fd: %d\n", fd);

    write(fd, parent_text, strlen(parent_text));
  }
  close(fd);
}