/* nm-naive.c */

/*
 * This component scans and maps the devices on a network. It provides insights
 * into the devices connected to the network, including IP addresses, open
 * ports, and services running on the devices.
 */

/* our own library */
#include "nm-naive.h"
#include <netinet/in.h>
/* builtin library */
/* declared variable which will used below */
int16 port;
in_addr_t current, ending;

/* this function will be used to increment to next ip address  */
in_addr_t generate() {

  int8 *p;
  int32 size;
  int8 buf[16];

  if ((!current) && (!ending)) {
    zero(buf, 16);
    fgets((char *)buf, 15, stdin);
    size = (int)strlen((char *)buf);
    if (size < 7)
      return (in_addr_t)0;
    size--;
    p = buf + size;
    if ((*p == '\n') || (*p == '\r'))
      *p = 0;

    return inet_addr((char *)buf);
  }

  if (current >= ending) {
    return (in_addr_t)0;
  } else {
    current++;
  }
  return current;
}

/* This fucntion will grab the banner */

int8 *header(int s, in_addr_t ip) {
  int16 i;
  static int8 buf[256];
  int8 *p;

  zero(buf, 256);
  i = read(s, (char *)buf, 255);
  if (i < 1)
    printf("0x%x\n", ip);
  else {
    i--;
    p = buf + i;
    if ((*p == '\n') || (*p == '\r'))
      *p = 0;
    printf("0x%x: %s\n", ip, buf);
  }
  return buf;
}

/* this will make conenction using TCP to that particular ip address and grab
 * the banner ... */

bool tcpconnect(in_addr_t ip, int16 port) {
  struct sockaddr_in sock;
  int s, ret;

  s = socket(AF_INET, SOCK_STREAM, 0);
  assert(s > 0);
  sock.sin_family = AF_INET;
  sock.sin_port = htons((int)port);
  sock.sin_addr.s_addr = ip;

  ret = connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr));

  if (ret) {
    close(s);
    return false;
  } else {
    header(s, ip);
    close(s);
    return true;
  }
  return false;
}

/* This represent the main function which we will be using for this network
 * mapper */

int main(int argc, char *argv[]) {

  in_addr_t ip;

  /* So this statement will check whether they provide necessary input to the
   * fucntion... */
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port> [start ip addr] [end up addr]\n", *argv);
    return -1;
  }

  /* This block will be used to assign the ip address to the variable which we
   * will be manipulating */
  if (argc > 2) {
    current = inet_addr(argv[2]);
    ending = (argc > 3) ? inet_addr(argv[3]) : inet_addr("255.255.254.255");
  }

  /* This block will check whether the pointer stores the ip if it doesn't raise
   * and error  */
  if ((current == INADDR_NONE) || (ending == INADDR_NONE) ||
      (ending < current)) {
    fprintf(stderr, "Usage: %s <port> [start ip addr] [end up addr]\n", *argv);
    return -1;
  }

  /* atoi() -> this function will convert the ASCII value into numbers
   * since argument we are porviding will be consider as string (char * )  */

  port = (int16)atoi(argv[1]);

  while ((ip = generate()))
    tcpconnect(ip, port);

  return 0;

  return 0;
}
