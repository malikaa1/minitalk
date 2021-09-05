#include <stdio.h>
int main(void) {
  unsigned int a = 60; //Equal to: 0011 1100
  unsigned int b = 13; // Equal to: 0000 1101
  
  int both = a & b; //If both are 0, then its a 0, 
  // if both are 1, then its a 1.  //0000 1100
  
  printf("%d\n", both);


}