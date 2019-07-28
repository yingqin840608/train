#include <stdio.h>

unsigned long long jiecheng(int n)
{
    if( (n == 0) || (n == 1)) {
        return 1;
    }
    else
    {
        return n * jiecheng(n - 1);
    }
}


int main()
{
    int a = 5;
	int i = 0;
	int lastnum = 0;

	unsigned long long sum = 0;
    unsigned long long value = 0;
    printf("Please input a number:");
    scanf("%d", &a);


	for(i = a; i > 0; i--)
	{
		sum += jiecheng(i);
	}
    lastnum = sum % 10;

    printf("jiecheng value=%llu, lastnum=%d\n", sum, lastnum);
    
}
