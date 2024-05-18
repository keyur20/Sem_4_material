#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_NODES 100
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES][MAX_NODES];

void floyd_warshall(int num_nodes)
{
    //intializing distance matrix with graph matrix
    for (int i = 0; i < num_nodes; i++)
    {
        for(int j = 0;j < num_nodes ; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    //performing dynamic approach
    for (int k = 0; k < num_nodes; k++)
    {
        for (int i = 0; i < num_nodes; i++)
        {
            for (int j = 0; j < num_nodes; j++)
            {
                //if vertex k is on shortest path from i to j update the distance 
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                     dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    

}

int main()
{
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d",&num_nodes);
    printf("Enter the elements in adjacency matrix: \n");
    for (int i = 0; i < num_nodes; i++)
    {
        for(int j = 0;j < num_nodes ; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    floyd_warshall(num_nodes);

    printf("The shortest distnace from all the pair of vertices:\n ");
    for(int i = 0; i < num_nodes; i++)
    {
        for(int j = 0;j < num_nodes ; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t",dist[i][j]);
            }
            
        }
        printf("\n");
    }

    return 0;
    

    


}



