/* netmap.h */

#define _GNU_SOURCE

/* Built-in library */

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

/* User defined library */

#include "/home/black/github/NetForge-Suite/libutils/libutils.h"

/* alias */

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
