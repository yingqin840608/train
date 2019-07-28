#include <stdio.h>
#define MAX_X  (10)
#define MAX_Y  (10)

typedef enum {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    DIRECT_ALL
}DirectE;

typedef struct {
    int x;
    int y;
}Pos;

/*创建迷宫*/
void CreateMaze(char array[MAX_X + 1][MAX_Y + 1]) {
    int i,j;
    for(i = 0; i < MAX_X; i++) {
        for(j = 0; j < MAX_Y; j++) {
            if(array[i][j] == 1) {
                printf("X ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}



/*迷宫问题*/
void TravelMaze(Pos start, Pos end) {
    Pos curPos;
    int i = 0;
    curPos = start;

    while(1) {
        if((curPos.x == end.x) && (curPos.y == end.y))
        {
            break;
        }
        for(i = 0; i < DIRECT_ALL; i++) {
            
        }
    }
    

}

char g_mapArray[MAX_X+1][MAX_Y+1] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

int main() {
    CreateMaze(g_mapArray);
}