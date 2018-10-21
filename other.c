#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
//Verision 2 stopping at square root
int sieve(double n) {
  int array_size;
  if (n>5000) {
    array_size = (int)(1.15*n*log(n));
  }
  else {
    array_size = (int)(1.3*n*log(n)+10);
  }
  char * nums = calloc(array_size,sizeof(char));

  int current_n = 0;
  int current_num = 1;
  int stopping_point = (int)sqrt(array_size);
  while (current_n != n) {
    current_num++;
    if (!(*(nums+current_num))){
      if (current_num < stopping_point){
        int temp_index = 2*current_num;
        while (temp_index < array_size){
          char * temp = nums+temp_index;
          if (!(*temp)){
            *temp = 1;
          }
          temp_index += current_num;
        }
      }
      current_n++;
    }
  }
  return current_num;
}
*/

/* Version 1 naive approach

int sieve(double n) {
  int array_size = 1;
  if (n>5000) {
    array_size = (int)(1.15*n*log(n));
  }
  else {
    array_size = (int)(1.3*n*log(n)+10);
  }
  char * nums = calloc(array_size,sizeof(char));

  int current_n = 0;
  int current_num = 1;
  while (current_n != n) {
    current_num++;
    if (!(*(nums+current_num))){
      int temp_index = 2*current_num;
      while (temp_index < array_size){
        char * temp = nums+temp_index;
        if (!(*temp)){
          *temp = 1;        }
        temp_index += current_num;
      }
      current_n++;
    }
  }
  return current_num;
}

printf("at: %d\ncurrent_num: %d\n7|6|5|4|3|2|1|0\n",temp_index,temp_current_num);
          temp_current_num += current_num;
          temp_index = temp_current_num >> 3;
          int i;
          for (i=7; i>=0; i--){
            printf("%d ",*temp >> i & 1);
          }
          printf("\n\n");
*/
