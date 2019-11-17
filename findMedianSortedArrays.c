#include <stdio.h>





double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int i = 0;
    int j = 0;

    int indexNum1 = 0;
    int indexNum2;

    indexNum2 = (nums1Size + nums2Size) / 2 - indexNum1;

    for(i = indexNum1; i < nums1Size; i++) {
        for(j = indexNum2; j >= 0; j--) {
            if(nums1[i] 
        }
    }


    return 0;
}

int main() {
    printf("hello, world");
    return 0;

}