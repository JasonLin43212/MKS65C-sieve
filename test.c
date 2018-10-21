#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_bit(char c){
  int i;
  for (i=0; i<8; i++){
    printf("%d",c&1);
    c >>= 1;
  }
  printf("\n");
}

int main() {
  char c = 76;
  printf("%d \n",c);
  print_bit(c);
  // setting the nth bit to 1 by doing c |= 1 << n indexed to 0
  c |= 1 << 5;
  print_bit(c);
  //checking the nth bit by doing c >> n & 1 indexed to 0
  printf("%d",c >> 9 & 1);
  // use c & 7 to do c % 8
  // use c >> 3 to do c / 8 (quotient)
}
