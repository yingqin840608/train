//最小生成树 普里姆算法    采用邻接矩阵存储  

#include <stdio.h>

#define  INFINITY  0xffffff
#define  MAXVEC    6


typedef struct {
    char start;
    char end;
    int  edgeLength;
} MEdge;

typedef struct {
    char nodenames;
    MEdge edges[MAXVEC - 1];
}MNode;

typedef struct {
    int numVertexes;
    MNode nodes[MAXVEC];
}MGraph;

//char nodeNames[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char nodeNames[] = {'0', '1', '2', '3', '4', '5'};
int arrayMap[MAXVEC][MAXVEC - 1] = {
    {6,1,5,INFINITY,INFINITY},
    {6,5,INFINITY,3,INFINITY},
    {1,5,5,6,4},
    {5,INFINITY,5,INFINITY,2},
    {INFINITY,3,6,INFINITY,6},
    {INFINITY,INFINITY,4,2,6}
    #if 0
    {7, INFINITY, 5, INFINITY, INFINITY, INFINITY},
    {7, 8, 9, 7, INFINITY, INFINITY},
    {INFINITY, 8, INFINITY, 5, INFINITY, INFINITY},
    {5, 9, INFINITY,15, 6, INFINITY},
    {INFINITY, 7, 5, 15, 8, 9},
    {INFINITY, INFINITY, INFINITY, 6, 8, 11},
    {INFINITY, INFINITY, INFINITY,INFINITY, 9, 11}
    #endif
};

void InitMGaph(MGraph *graph)
{
    int i = 0;
    int j = 0;
    int k = 0;

    graph->numVertexes = MAXVEC;
    for(i = 0; i < MAXVEC; i++) {
        k = 0;
        graph->nodes[i].nodenames = nodeNames[i];
        for(j = 0; j < MAXVEC - 1; j++) {
            graph->nodes[i].edges[j].start = nodeNames[i];
            if(graph->nodes[i].nodenames == nodeNames[k]) {
                k++;
            }
            graph->nodes[i].edges[j].end = nodeNames[k]; 
            graph->nodes[i].edges[j].edgeLength = arrayMap[i][j];
            k++;
        }
    }
}


void PrintGraph(MGraph *graph) 
{
    int i = 0;
    int j = 0;
    for(i = 0; i < MAXVEC; i++) {
        for(j = 0; j < MAXVEC - 1; j++) {
            if(graph->nodes[i].edges[j].edgeLength != INFINITY) {
                printf("%c<->%c:%d ",graph->nodes[i].edges[j].start, 
                 graph->nodes[i].edges[j].end, graph->nodes[i].edges[j].edgeLength);
            }
        }
        printf("\n");
    } 
}

typedef struct {
    char vertexData;
    int lowercost;
}closedge;

closedge mst[MAXVEC];

void MiniSpanTree(MGraph *G, char nodeName)
{
    int s;
    for(int i = 0; i < MAXVEC; i++) {
        mst[i].lowercost = INFINITY;
    }
    s = nodeName - '0';
    mst[s].vertexData = nodeName;
    mst[s].lowercost = 0;

    for(int i = 0; i < MAXVEC; i++) {
        if(i != s) {
            mst[i].vertexData = s + '0';
            mst[i].lowercost = 
        }
    }

}

#if 0
void MiniSpanTree(MGraph *G)  
{  
    int min, i, j, k;  
    int adjvex[MAXVEC];     //保存相关顶点下标  
    int lowcost[MAXVEC];    //保存相关顶点间边的权值  
    lowcost[0] = 0;         //初始化第一个权值为0，即V0加入生成树  
    adjvex[0] = 0;          //初始化第一个顶点下标为0  
  
    //初始化操作
    for (i=0; i < G->numVertexes - 1; ++i)  
    {  
        lowcost[i] = G->nodes[0].edges[i].edgeLength;
        adjvex[i+1] = 0;              //将v0顶点与之有边的权值存入数组  并初始化都为v0的下标  
    }  //adjvex[i]，i是其他节点的标记，adjvex[i]=0即是把0~n的节点都与节点0关联起来
  
    for (i=1; i<G->numVertexes; ++i)  
    {  
        min = INFINITY;  
    
        j = 1;  
        k = 0;  //保存权值最小的顶点
        //遍历v-u集合中剩下的节点
        while (j < G->numVertexes)  
        {  
            //如果两个顶点之间存在边并且权值小于min  
            if (lowcost[j]!=0 && lowcost[j] < min)  
            {  
                min = lowcost[j];  
                k = j;  
            }  
            ++j;  
        }  
        printf("(%d, %d)", adjvex[k], k);   //输出当前顶点边中权值最小的边  
        lowcost[k] = 0;                     //将当前顶点的权值设为0，表示此顶点已经完成任务  

        //更新新节点与其他节点之间的最小花费和关联
        for (j=1; j<G->numVertexes; ++j)  
        {  
            if (lowcost[j]!=0 && G->arc[k][j]<lowcost[j])  
            {  
                lowcost[j] = G->arc[k][j];  
                adjvex[j] = k;  
            }  
        }  
    }  
}
#endif


int main() 
{
    MGraph myGraph;
    InitMGaph(&myGraph);
    PrintGraph(&myGraph);
    //MiniSpanTree(&myGraph);
}





