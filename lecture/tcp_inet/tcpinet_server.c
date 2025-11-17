#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  // socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // bind
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(1042);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) ==
      -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // listen
  if (listen(socket_fd, 1) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // accept
  int connect_fd = accept(socket_fd, NULL, NULL);
  if (connect_fd == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // read
  while (1) {
    char buff[100];
    int len = read(connect_fd, buff, 100);
    if (buff[len - 1] == '\0')
      len--;
    if (len == 4 && strncmp(buff, "exit", 4) == 0)
      break;
    write(STDOUT_FILENO, buff, len);
    write(STDOUT_FILENO, "\n", len);
  }

  // close
  close(socket_fd);
  close(connect_fd);
  return 0;
}
