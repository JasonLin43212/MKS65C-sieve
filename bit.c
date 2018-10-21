#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int targetPrime) {
  int array_size;
  if (targetPrime>5000) {array_size = (int)(0.144*targetPrime*log((double)targetPrime));}
  else {array_size = (int)(0.163*targetPrime*log((double)targetPrime)+5);}
  char * nums = calloc(array_size,sizeof(char));
  if (targetPrime != 1) {
    int current_n = 1;
    int current_num;
    int temp_index;
    char * temp;
    for (current_num = 1;current_n != targetPrime; current_num++) {
      if (!(((*(nums+(current_num >> 3))) >> (current_num & 7)) & 1)){
        if (current_num * current_num < array_size * 8){
          int temp_current_num = current_num + current_num + current_num + 1;
          for (temp_index = temp_current_num >> 3;
               temp_index < array_size;
               temp_current_num += current_num + current_num + 1,
                 temp_index = temp_current_num >> 3){
            temp = nums+temp_index;
            if (!((*temp) >> (temp_current_num & 7) & 1)){
              *temp |= 1 << (temp_current_num & 7);
            }
          }
        }
        current_n++;
      }
    }
    return current_num + current_num +1;
  }
  else {
    return 2;
  }
}
