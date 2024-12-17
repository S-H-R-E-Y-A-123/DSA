//DFS | adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of vertices

void DFS(int G[MAX][MAX], int n, int start, int visited[MAX]) {
    visited[start] = 1; // Mark the current node as visited
    printf("%d ", start); // Print the current node

    // Recur for all adjacent nodes
    for (int v = 0; v < n; v++) {
        if (G[start][v] == 1 && !visited[v]) { // Check if there is an edge and if node v is not visited
            DFS(G, n, v, visited); // Recursive DFS call for unvisited adjacent nodes
        }
    }
}

int main() {
    int G[MAX][MAX], n, start;
    int visited[MAX] = {0}; // Array to track visited nodes

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("\nEnter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal starting from node %d:\n", start);
    DFS(G, n, start, visited); // Call DFS function

    return 0;
}
