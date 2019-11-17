#include "common.h"


void print(int* nums, int numsSize) 
{
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
