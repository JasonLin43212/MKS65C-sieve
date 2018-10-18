#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(double n) {
  int array_size = 1;
  if (n>5000) {
    array_size = (int)(1.15*n*log(n));
  }
  else {
    array_size = (int)(1.3*n*log(n)+10);
  }
  printf("%d",array_size);
  char * nums = malloc(array_size);

  int current_n = 0;
  int current_num = 2;
  while (current_n != n) {
    printf("%d\n%d\n",current_num,current_n);
    if (!nums) {
      printf("found prime\n");
      current_n++;
      char * temp = nums + current_num;
      int temp_index = 2*current_num;
      while (temp_index < array_size) {
        *temp = 1;
        temp += current_num;
        temp_index += current_num;
      }
    }
    current_num++;
  }

  return current_num-1;
}
