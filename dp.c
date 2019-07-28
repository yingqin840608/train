#include <stdio.h>
#include <stdlib.h>

#define E_OK 0
#define E_NOT_OK 1
#define MAX_COMP (0xFF)

int componentList[] = {1, 2, 5, 10};
int comp[MAX_COMP + 1] = {0};

int min(int a, int b) {
    if(a >= b) {
        return b;
    } else {
        return a;
    }
}

void printArray(int *pArray, int arraySize) {
    int i = 0;
    if(pArray != NULL) {
        for(i = 1; i <= arraySize; i++)
        {
            printf("%d ", pArray[i]);
            if(i % 10 == 0) {
                printf("\n");
            }
        }
    }
}


int main()
{
    int dollar = 0;
    int i = 0;
    int j = 0;
    int cost = 0;

    int *pArrayList = NULL;

    printf("Input the composed dollar value:\n");
    scanf("%d", &dollar);

    pArrayList = (int *)malloc(sizeof(int) * (dollar + 1));
    if(pArrayList == NULL) {
        printf("malloc failed\n");
        return E_NOT_OK;
    }

    pArrayList[0] = 0;

    for(i = 1; i <= dollar; i++)
    {
        cost = MAX_COMP;

        for(j = 0; j < sizeof(componentList) / sizeof(int); j++)
        {
            if(i - componentList[j] >= 0) {
                if(cost >= pArrayList[i - componentList[j]] + 1) {
                    cost = pArrayList[i - componentList[j]] + 1;
                    comp[cost] = componentList[j];
                }
            }
        }
        pArrayList[i] = cost;
    }

    printArray(pArrayList, dollar);

    printf("\n dollar %d min comp is:\n", dollar);

    printArray(comp, cost);
    
    return 0;
} 