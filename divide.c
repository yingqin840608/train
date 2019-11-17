#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    int ret;
    unsigned int divValue = 0;
    unsigned int absDividend;
    unsigned int absDivisor;
    unsigned int value = 0;
    unsigned int i = 0;

    if(dividend < 0) {
        if(dividend == INT_MIN) {
            absDividend = (unsigned int)INT_MAX + 1;
        } else {
            absDividend = -dividend;
        }
    } else {
        absDividend = dividend;
    }

    if(divisor < 0) {
        if(divisor == INT_MIN) {
            absDivisor = (unsigned int)INT_MAX + 1;
        } else {
            absDivisor = -divisor;
        }
    } else {
        absDivisor = divisor;
    }

    if(absDividend < absDivisor) {
        return 0;
    }

    while(absDividend > 0) {
        i = 1;
        value = absDivisor;
        while( (value << 1) <= absDividend) {
            value = value << 1;
            i = i << 1;
        }

        if(absDividend > absDivisor) {
            divValue += i;
        } else {
            break;
        }
        absDividend -= value;
    }
    
    if(divValue > INT_MAX) {
        return INT_MAX;
    }

    ret = divValue;
    if( ((dividend >= 0) && (divisor < 0)) &&
        ((dividend <= 0) && (divisor > 0)) )
    {
        ret = -ret;
    } 

    return ret;
}

int main()
{
    int ret;
    ret = divide(100, 33);
    printf("%d", ret);
    return 0;
}