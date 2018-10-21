#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int targetPrime) {
  int array_size;
  if (targetPrime>5000) {array_size = (int)(0.575*targetPrime*log((double)targetPrime));}
  else {array_size = (int)(1.3*targetPrime*log((double)targetPrime)+10);}
  printf("size:%d",array_size);
  char * nums = calloc(array_size,sizeof(char));
  if (targetPrime != 1){
    int current_n = 1;
    int current_num;
    int temp_index;
    char * temp;
    printf("\n");
    for (current_num = 3; current_n != targetPrime; current_num += 2) {
      printf("Current num: %d\n",current_num);
      if (!(*(nums+(current_num >> 1)))){
        printf(" and %d went through!\n",current_num);
        if (current_num < array_size){
          for (temp_index = current_num * current_num;
               temp_index < array_size;
               temp_index += current_num + current_num){

            temp = nums + (temp_index >> 1);
            if (!(*temp)){
              *temp = 1;
            }
            printf("1 |3 |5 |7 |9 |11|13|15|17|19|21|23|25|27|29|31|33\n");
            int i;
            for (i=0;i<19;i++){
              printf("%d |",*(nums+i));
            }
            printf("\n");
          }
        }
        current_n++;
      }
    }
    return current_num;
  }
  else {
    return 2;
  }
}
