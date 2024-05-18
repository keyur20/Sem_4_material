#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 10

int tsp(int n, int graph[][MAX_N], int start, int visited_all) {
    int dp[MAX_N][1 << MAX_N];

    // Initialize dp array with maximum distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = INT_MAX;
        }
    }

    // Base case: If there are no more unvisited cities, return the distance to the starting city
    if (visited_all == (1 << n) - 1) {
        return graph[start][0];
    }

    // If the subproblem is already solved, return the stored result
    if (dp[start][visited_all] != INT_MAX) {
        return dp[start][visited_all];
    }

    // Iterate over all possible next cities
    for (int i = 0; i < n; i++) {
        // Check if the city is unvisited
        if ((visited_all & (1 << i)) == 0) {
            // Mark the city as visited
            int new_visited = visited_all | (1 << i);

            // Calculate the distance from the current city to the next city and recursively solve the subproblem
            int distance = graph[start][i] + tsp(n, graph, i, new_visited);

            // Update the minimum distance
            if (distance < dp[start][visited_all]) {
                dp[start][visited_all] = distance;
            }
        }
    }

    // Store the computed result
    return dp[start][visited_all];
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX_N][MAX_N];

    // Input the distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Calculate the minimum distance using TSP
    int min_distance = tsp(n, graph, 0, 1);

    // Output the minimum distance
    printf("The minimum distance of the TSP is: %d\n", min_distance);

    return 0;
}
