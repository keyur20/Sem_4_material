#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start_node, int num_nodes)
{
    // Initialize all distances to infinity except for the start node
    for (int i = 0; i < num_nodes; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start_node] = 0;

    // Main loop
    for (int i = 0; i < num_nodes - 1; i++)
        {
        // Find the node with the minimum distance
        int min_dist = INT_MAX;
        int min_node = -1;
        for (int j = 0; j < num_nodes; j++)
        {
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_node = j;
            }
        }

        // Mark the current node as visited
        visited[min_node] = 1;

        // Update the distances of all neighboring nodes
        for (int j = 0; j < num_nodes; j++)
            {
            if (!visited[j] && graph[min_node][j] != 0 && dist[min_node] + graph[min_node][j] < dist[j])
            {
                dist[j] = dist[min_node] + graph[min_node][j];
            }
        }
    }
}

int main()
{
    int num_nodes, start_node;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the start node: ");
    scanf("%d", &start_node);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra(start_node, num_nodes);

    printf("Shortest distances from node %d:\n", start_node);
    for (int i = 0; i < num_nodes; i++)
    {
        printf("%d -> %d: %d\n", start_node, i, dist[i]);
    }

    return 0;
}
