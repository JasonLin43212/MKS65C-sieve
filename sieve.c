#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_ints(char * c, int size) {
  int current = 0;
  while (current < size) {
    printf("%d: %d\n",current+2,*c);
    c++;
    current++;
  }
}

//Verision 2 removing all even nums
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
            *temp = 1;        }
          temp_index += current_num;
        }
      }
      current_n++;
    }
  }
  return current_num;
}

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
*/
