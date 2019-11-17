#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"


#if 0
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int j;
    long long digit;
    long long value = 0;
    long long computeValue;
    int *retValue;
    int *reverseValue;
    
    for(i = digitsSize - 1; i >= 0; i--) {
        j = i;
        digit = digits[i];
        while(j < digitsSize - 1) {
            digit = digit * 10;
            j++;
        }
        value += digit;
    }
    
    retValue = (int *)malloc(sizeof(int) * (digitsSize + 1));
    reverseValue = (int *)malloc(sizeof(int) * (digitsSize + 1));
    
    computeValue = value + 1;
    i = 0;
    while(computeValue != 0) {
        reverseValue[i++] = computeValue % 10;
        computeValue = computeValue / 10;
    }

    *returnSize = i;
    i = 0;
    for(j = *returnSize - 1; j >=0; j--) {
        retValue[i++] = reverseValue[j];
    }
    free(reverseValue);
    return retValue;
}
#endif

int* plusOneBetter(int* digits, int digitsSize, int* returnSize){
    int *num = (int*)malloc(sizeof(int) * (digitsSize + 1));
    num[0] = 1;
    int i;
    for (i = digitsSize - 1; i >= 0; i--){
        if (digits[i] == 9)
            digits[i] = 0;
        else{
            digits[i] += 1;
            break;
        }
    }
    *returnSize = (digits[0] == 0) ? (digitsSize + 1) : digitsSize;
    for (i = 0; i < digitsSize; i++){
        num[i + 1] = digits[i];
    }
    return (digits[0] == 0) ? num : digits;       
}


int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int i;
    int j = 0;
    int digit;
    int *retList; 
    int *retReverse;
    int index;

    retList = (int *)malloc(sizeof(int) * (digitsSize + 1));
    retReverse = (int *)malloc(sizeof(int) * (digitsSize + 1));
    j = 0;

    for(i = digitsSize - 1; i >= 0; i--) {
        if(digits[i] == 9) {
            retReverse[j++] = 0;
            continue;
        } else {
            retReverse[j++] = digits[i] + 1;
            break;
        }
    }
    
    index = i;
    if ((index <= 0) && (digits[0] == 9)) {
        retReverse[digitsSize] = 1;
        *returnSize = digitsSize + 1;
    } else {
        for(i = index - 1; i >= 0; i--) {
            retReverse[j++] = digits[i];
        }
        *returnSize = digitsSize;
    }

    i = 0;
    for(j = *returnSize - 1; j >=0; j--) {
        retList[i++] = retReverse[j];
    }
    free(retReverse);
    return retList;
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
    int *p;
    int singList[]={2,2,3};
    int singList1[]={9};
    int singList2[]={9,9};
    int singList3[]={0};
    p = plusOne(singList, ARRAY_SIZE(singList), &ret);

    p = plusOne(singList1, ARRAY_SIZE(singList1), &ret);
    p = plusOne(singList2, ARRAY_SIZE(singList2), &ret);

    p = plusOne(singList3, ARRAY_SIZE(singList3), &ret);

    return 0;
}