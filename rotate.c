#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {
    int i = 0;
    int index = 0;
    int tmp;
    int *p;

    if ((nums == NULL) || (numsSize == 0)) {
        return;
    }
    if (k < 0) {
        return;
    }
    
    p = (int *)malloc(sizeof(int) * numsSize);
    k = k % numsSize;
    
    for(i = numsSize - k; i < numsSize; i++) {
        tmp = nums[i];
        p[index++] = tmp;
    }
    
    for(i = 0; i < numsSize - k; i++) {
        tmp = nums[i];
        p[index++] = tmp;
    }
    
    memcpy(nums, p, sizeof(int) * numsSize);
    free(p);
} 

void print(int* nums, int numsSize) 
{
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main()
{
    int rotateList[]={1,2,3,4,5,6,7};

    rotate(rotateList, sizeof(rotateList)/sizeof(rotateList[0]), 1);

    print(rotateList, sizeof(rotateList)/sizeof(rotateList[0]));

    int rotateList1[]={1,2,3,4,5,6,7};
    rotate(rotateList1, sizeof(rotateList1)/sizeof(rotateList1[0]), 2);
    print(rotateList1, sizeof(rotateList1)/sizeof(rotateList1[0]));

    return 0;
}