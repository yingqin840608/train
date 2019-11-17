#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int removeDuplicates(int* nums, int numsSize) 
{
    int i = 0;
    int j = 0;
    int min;
    int quitflag = 0;
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }
    for(i = 0; i < numsSize; i++) {
        if(i == 0) {
            min = nums[i];
            continue;
        }
        while(min == nums[i]) {
            i++;
            if(i == numsSize) {
                break;
                quitflag = 1;
            }
        }
        if(quitflag) {
            break;
        }
        j++;
        nums[j] = nums[i];
        min = nums[j];
    }
    return j+1;
}
#endif

int removeDuplicates(int* nums, int numsSize) 
{
    int i = 0,j = 0;
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }
    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j+1;
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
    int nums[] = {1, 1, 2};
    int ret = 0;
    ret = removeDuplicates(nums, sizeof(nums)/sizeof(nums[0]));
    print(nums, ret);

    int nums1[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5};
    ret = removeDuplicates(nums1, sizeof(nums1)/sizeof(nums1[0]));
    print(nums1, ret);

    int nums2[] = {1, 2, 3, 4, 5};
    ret = removeDuplicates(nums2, sizeof(nums2)/sizeof(nums2[0]));
    print(nums2, ret);

    int nums3[] = {1, 2, 3, 4, 5, 5};
    ret = removeDuplicates(nums3, sizeof(nums3)/sizeof(nums3[0]));
    print(nums3, ret);
    
}