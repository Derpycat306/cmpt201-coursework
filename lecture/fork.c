#include <stdio.h>
#include <unistd.h>

int main() {
  for (int i = 0; i < 5; i++) {
    fork();
    printf("Sleeping\n");
    sleep(1);
    fflush(stdout);
  }
}
