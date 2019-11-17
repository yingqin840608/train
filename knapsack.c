#include <stdio.h>
#include <math.h>

#define NUM 50
#define CAP 1500

int v[NUM];
int w[NUM];
int p[NUM][CAP];

int min(int a, int b) {
    if(a >= b) {
        return b;
    } else {
        return a;
    }
}


int max(int a, int b) {
    if(a >= b) {
        return a;
    } else {
        return b;
    }
}

void knapsack(int c, int n)
{
    int j;
    int jMax = min(w[n] - 1, c);
    for(j = 0; j <= jMax; j++) {
        p[n][j] = 0;
    }

    for(j = w[n]; j <= c; j++) {
        p[n][j] =v[n];
    }
    
    for(int i = n - 1; i > 1; i--) {
        jMax = min(w[i] - 1, c);
        for(j= 0; j <= jMax; j++) {
            p[i][j] = p[i+1][j];
        }
        for(j = w[i]; j<=c; j++) {
            p[i][j] = max(p[i+1][j], p[i+1][j-w[i]] + v[i]);
        }
        p[1][c] = p[2][c];
        if(c >= w[1]) {
            p[1][c] = max(p[1][c], p[2][c-w[1]] + v[1]);
        }
    }
}

void traceback(int c, int n, int x[]) 
{
    for (int i = 1; i < n; i++) {
        if(p[i][c] == p[i+1][c]) {
            x[i] = 0;
        } else {
            x[i] = 1; 
            c -= w[i];
        }
    }
    x[n] = p[n][c] ? 1:0;
}