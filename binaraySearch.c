#include <stdio.h>


typedef int type;

int BinarySearch(type a[], const type x, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if(x == a[middle]) {
            return middle;
        }
        if(x > a[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}


int main() {
    type intarray[] = {1, 3, 5, 9, 13, 23,133,147,1550};
    int ret = BinarySearch(intarray, 11, sizeof(intarray)/sizeof(intarray[0]));
}