#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_handler() {
  const char *message = "^C has been used";
  write(STDOUT_FILENO, message, strlen(message));
}

int main() {
  struct sigaction act;
  act.sa_handler = print_handler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);

  int pid = fork();

  if (pid) {
    int ret = sigaction(SIGINT, &act, NULL);
    if (ret == -1) {
      exit(EXIT_FAILURE);
    }
    while (true) {
      sleep(1);
    }
  } else {
    sleep(1);
    kill(getppid(), SIGINT);
  }
}
