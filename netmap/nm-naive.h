
#include "netmap.h"
#include <netinet/in.h>

int main(int, char **);
in_addr_t generate(void);
int8 *header(int, in_addr_t);
bool tcpconnect(in_addr_t, int16);
