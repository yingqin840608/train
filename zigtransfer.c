#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char * s, int numRows) 
{
    int i = 0;
    int j;
    int k = 0;
    int flag = 1;
    int maxLen = strlen(s);
    char *p;
    p = (char *)malloc(maxLen+1);

    if(numRows < 2) {
        return s;
    }

    for(i = 0; i < numRows; i++) {
        j = i;
        flag = 1;
        while(j < maxLen && s[j] != '\0') {
            if(i == 0) {
                p[k++] = s[j];
                j += (numRows-i-1) * 2;
            } else if(i == numRows-1) {
                p[k++] = s[j];
                j += i * 2;
            } else if(flag == 1) {
                flag = 0;
                p[k++] = s[j];
                j += (numRows-i-1) * 2;
            } else if(flag == 0) {
                flag = 1;
                p[k++] = s[j];
                j += i * 2;
            }
        }
    }
    p[k] = '\0';
    return p;
}

int main()
{
    char *s;
    s = convert("LEETCODEISHIRING", 3);
    printf("%s", s);
    printf("\n");

    char *p;
    p = convert("LEETCODEISHIRING", 4);
    printf("%s", p);
}