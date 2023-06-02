#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 1;
  pid_t pid;
  pid = fork();

  if (pid == 0) {
    x++;
    printf("x = %d\n", x);
    printf("In child\n");
    pid_t ppid = getppid();
    printf("Parent pid = %d\n", ppid);
    pid_t rpid = getpid();
    printf("Returned pid = %d\n", rpid);
  } else {

    x--;
    printf("x = %d\n", x);
    sleep(1); //sleep for 1 second
    printf("In parent\n");
    pid_t mypid = getpid(); 
    printf("Child pid = %d\n", pid);
    printf("Parent pid = %d\n", mypid);
  }
  return(0);
}
