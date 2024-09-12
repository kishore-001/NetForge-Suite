/* nm-naive.c */

/*
 * This component scans and maps the devices on a network. It provides insights
 * into the devices connected to the network, including IP addresses, open
 * ports, and services running on the devices.
 */

/* our own library */
#include "./../libutils/libutils.h"
#include "netmap.h"
/* builtin library */
#include <stdio.h>
/* declared variable which will used below */
int16 port;
in_addr_t current, ending;

/* this function will be used to increment to next ip address  */
in_addr_t generate() {

  int8 buf[16];

  if ((!current) && (!ending)) {
    zero(buf, 16);
    fgets(buf, 15, stdin);
  }

  if (current >= ending) {
    return (in_addr_t)0;
  } else {
    current++;
  }
  return current;
}

/* This represent the main function which we will be using for this network
 * mapper */

int main(int argc, char *argv[]) {

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

  printf("Start: %d\nEnd: %d\nPort: %d\n", current, ending, port);

  return 0;
}
