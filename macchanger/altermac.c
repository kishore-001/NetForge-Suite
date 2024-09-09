/*altermac.c*/
#define _GNU_SORCE_ //Gives the gnu based extensions
#include<stdio.h>
#include<unistd.h> 
#include<strings.h>
#include<stdlib.h>
#include<errno.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

struct s_mac{
  int64 addr:48; // mac address is 48 bits long
};

typedef struct s_mac MAC;

MAC generatemac(void); // function to generate the random mac address
int main(int, char**);  // main function

MAC generatemac(void){
  int64 x, y;
  MAC mac;
  x=(long)random(); // creates the two big random number
  y=(long)random();
  mac.addr = ((a*b)% 281474976710656 ); // we are limmiting the address generation from 0 -> 281474976710656
  return mac; // now we can return a struct
}


int main(){
  srand(getpid()); // seed the random number generator

  return 0;
}

