#include <stdio.h>
#include <math.h>
#define N  (3*3*3*3*3*3)
typedef unsigned char uint8;

uint8 array[N+1][N+1] = { {0} };

void set(int n, int x, int y)
{   
    if(n == 1) {
        array[x][y] = 1;
        return;
    } else {
        set(n - 1, x, y);
        set(n - 1, x, y + 1);
        set(n - 1, x + 1, y);
        set(n - 1, x + 2, y);
        set(n - 1, x + 2, y + 1);
    }
}

void print() {
    int i;
    int j;
    uint8 bPrintNewLine = 0;
    for(i = 1; i < N+1; i++) {
        bPrintNewLine = 0;
        for(j = 1; j < N + 1; j++) {
            if(array[i][j] == 1) {
                printf("X");
                bPrintNewLine = 1;
            }
        }
        if(bPrintNewLine == 1) {
            printf("\n");
        }
    }
}

int main()
{
    set(3, 1, 1);
    print();
    return 0;
}