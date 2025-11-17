#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  // socket
  int socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  remove("udpsocket");

  // bind
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  snprintf(addr.sun_path, 108, "udpsocket");
  if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) ==
      -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
  socklen_t addrsize = sizeof(struct sockaddr_un);

  // receive
  while (1) {
    char buff[100];
    int len =
        recvfrom(socket_fd, buff, 100, 0, (struct sockaddr *)&addr, &addrsize);
    if (buff[len - 1] == '\0')
      len--;
    if (len == 4 && strncmp(buff, "exit", 4) == 0)
      break;
    write(STDOUT_FILENO, buff, len);
  }

  // close
  close(socket_fd);
  return 0;
}
