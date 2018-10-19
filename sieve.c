#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(double n) {
  int array_size;
  if (n>5000) {
    array_size = (int)(0.575*n*log(n));
  }
  else {
    array_size = (int)(0.65*n*log(n)+5);
  }
  char * nums = calloc(array_size,sizeof(char));
  if (n != 1){
    int current_n = 1;
    int current_num = 0;
    while (current_n != n) {
      current_num++;
      if (!*(nums+current_num)){
        if (current_num * current_num < array_size){
          int temp_index = current_num + current_num + current_num + 1;
          while (temp_index < array_size){
            char * temp = nums+temp_index;
            if (!*temp){
              *temp = 1;
            }
            temp_index += current_num + current_num + 1;
          }
        }
        current_n++;
      }
    }
    return current_num + current_num+1;
  }
  else {
    return 2;
  }
}
