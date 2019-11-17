#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int singleNum(int* nums, int numsSize) 
{
    int i;
    int j;
    int tmp;
    int flag = 0;
    if(numsSize % 2 == 0) {
        return -1;
    }

    for (i = 0; i < numsSize; i++) {
        tmp = nums[i];
        flag = 0;
        for(j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            if (tmp == nums[j]) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            return tmp;
        }
    }
    return -1;
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
    int ret;
    int singList[]={2,2,3};

    ret = singleNum(singList, sizeof(singList)/sizeof(singList[0]));
    printf("%d\n", ret);

    int singList1[] = {4,1,2,1,2};
    ret = singleNum(singList1, sizeof(singList1)/sizeof(singList1[0]));
    printf("%d\n", ret);


    return 0;
}