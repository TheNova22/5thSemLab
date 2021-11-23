#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define INFINTY 1000
int cost[20][20],totalNodes,source,paths[20],visited[20],distance[20];
int i,j,seen,min, count;
void dji(){
    for(i = 0; i < totalNodes; i++){
        distance[i] = cost[source][i];
        visited[i] = 0;
        paths[i] = source;
    }
    distance[source] =0;
    visited[source] = 1;
    count = 1;
    while (count < totalNodes){
        min = INFINTY;
        for (i = 0; i < totalNodes; i++)
        {
            if (distance[i] < min && !visited[i]){
                min = distance[i];
                seen = i;
            } 
        }
        visited[seen] = 1;
        for (i = 0; i < totalNodes; i++)
        {
            if (!visited[i]){
                if (min + cost[seen][i] < distance[i]){
                    distance[i] = min + cost[seen][i];
                    paths[i] = seen;
                }
            }
        }
        count++;
    }
    for ( i = 0; i < totalNodes; i++)
    {
        if (i != source){
            printf("Distance of %d from %d is %d \n",i,source,distance[i]);
            printf("Path is : %d",i);
            j = i;
            do{
                j = paths[j];
                printf("<- %d",j);
            }while(j != source);
            printf("\n");
        }
    }
    
}

void main(){
    printf("\nEnter the number of vertices");
    scanf("%d",&totalNodes);
    printf("\nEnter the cost matrix:\n");
    for(int i=0;i<totalNodes;i++){
        for(int j=0;j<totalNodes;j++){
            scanf("%d",&cost[i][j]);
            cost[i][i] = 0;
            if(cost[i][j] == 0 && i != j){
                cost[i][j] = INFINTY;
            }
        }
    }
    printf("\nEnter the starting node: ");
    scanf("%d",&source);
    dji();
}