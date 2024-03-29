#include <stdio.h>
#include <string.h>
#define NUM 100


int c[NUM][NUM];
int b[NUM][NUM];

void LCSLength(int m, int n, const char x[], const char y[])
{
    int i, j;
    for(i = 1; i <= m; i++) {
        c[i][0] = 0;
    }
    for(i = 1; i <= n; i++) {
        c[0][i] = 0;
    }

    for(i = 1; i <=m; i++) {
        for(j=1; j<=n; j++) {
            if(x[i] == y[j]) {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            } else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

void LCS(int i, int j, char x[]) 
{
    if(i == 0 || j == 0) return;
    if(b[i][j] == 1) {
        LCS(i-1,j-1,x);
        printf("%c", x[i]);
    } else if(b[i][j] == 2) {
        LCS(i-1, j, x);
    } else {
        LCS(i, j-1, x);
    }
}

int main()
{
   char *str1 = "abcdefgh";
   char *str2 = "efds";
   LCSLength(strlen(str1), strlen(str2), str1, str2);
}
