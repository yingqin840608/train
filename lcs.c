/***************************************************************
 * ************************************************************* 
 ************************************************************** 
 * *************************************************************
 *   C[i,j] =  C[i-1, j- 1] + 1  if x[i] = y[j]
 *   C[i,j] =  max(c[i, j-1], c[i - 1][j])   
 * *************************************************************
 ************************************************************** 
 * *************************************************************
 ************************************************************** 
 ************************************************************** 
 * */
#include <stdio.h>
#include <string.h>
#include <math.h>


#define X "ABCDEFBADE"
#define Y "ACDEBD"
#define MAX_LENGTH 12

char g_lcs[MAX_LENGTH] = {0};
char c[MAX_LENGTH][MAX_LENGTH] = { {0} };

int min(int x, int y) 
{
    if(x <= y) {
        return x;
    } else {
        return y;
    }
}

int max(int x, int y) {
    if(x >= y) {
        return x;
    } else {
        return y;
    }
}

/*回溯法*/
void GetLscStr(char *str1, char *str2, char *pLcs) 
{
    int i = 0;
    int j = 0;

    int rs = strlen(str1);
    int vs = strlen(str2);
    int curMax = 0;
    if(rs >= vs) {
        for(j = vs; j > 0; j--) {
            curMax = c[i][j];
            if( (curMax > c[i-1][j]) && (curMax > c[i][j - 1])) {
                pLcs[j] = str2[j-1];
                i--;
            } else {
                if(c[i-1][j] >= c[i][j-1]) {
                    pLcs[j] = str2[j-1];
                    i--;
                    j++;
                } else {
                    pLcs[j] = c[i][j-1];
                }
            }
        }
    } else {
        for(i = rs; i > 0; i--) {
            curMax = c[i][j];
            if( (curMax > c[i-1][j]) && (curMax > c[i][j - 1])) {
                pLcs[i] = curMax;
                j--;
            } else {
                if(c[i][j-1] >= c[i-1][j]) {
                    pLcs[i] = c[i][j-1];
                    j--;
                } else {
                    pLcs[i] = c[i-1][j];
                }
            }
        }
    }
}


void GetLcs(char *str1, char *str2, char *pLcs) 
{
    int lenx = 0;
    int leny = 0;
    int minLength;
    int i, j;
    lenx = strlen(str1);
    leny = strlen(str2);
    
    minLength = min(lenx, leny);

    if((lenx == 0) || (leny == 0)) {
        return;
    } 

    for(i = 0; i < lenx; i++) {
        c[i][0] = 0;
    }
    for(j = 0; j < leny; j++) {
        c[0][j] = 0;
    }

    for(i = 1; i <= lenx; i++) {
        c[i][j] = 0;
        for(j = 1; j <= leny; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    GetLscStr(lenx, leny, pLcs);
}

void print(int rs, int hs) 
{
    int i, j;
    for(i = 0; i <= rs; i++) {
        for(j = 0; j <= hs; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    GetLcs(X, Y, g_lcs);
    print(strlen(X), strlen(Y));
    printf("lcs=%s\n", g_lcs);
}
