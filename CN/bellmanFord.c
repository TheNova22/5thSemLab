#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define INFINTY 1000

int G[20][20],edge[20][2], totalNodes, totalEdges, source, distance[20], parent[20];
int i,j,k, flag;

void bellmanFord(){
    int u,v;

    for(i = 0; i < totalNodes;i++){
        distance[i] = INFINTY;
        parent[i] = -1;
    }
    distance[source] = 0;

    for(i = 0; i < totalNodes; i++){
        for(j = 0; j < totalEdges;j++){
            u = edge[j][0];
            v = edge[j][1];
            if (distance[u] + G[u][v] < distance[v]){
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }
    for(i = 0; i < totalNodes; i++){
        printf("Vertex %d --> Cost %d --> Parent %d\n", i, distance[i],parent[i]);
    }
}


void main(){
    printf("Enter total number of nodes: \n");
    scanf("%d",&totalNodes);
    printf("Enter the adjacency matrix: \n");
    k = 0;
    for(i = 0; i < totalNodes; i++){
        for(j = 0; j < totalNodes;j++){
            scanf("%d",&G[i][j]);
            G[i][i] = 0;
            if (G[i][j] != 0){
                edge[k][0] = i;
                edge[k][1] = j;
                k ++;
            }
            
        }
    }
    totalEdges = k;
    printf("Enter the source node: \n");
    scanf("%d",&source);
    bellmanFord();
    
}