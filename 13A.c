// BFS | adjcency matrix

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of vertices

void BFS(int G[MAX][MAX], int n, int start) {
    int visited[MAX] = {0}; // Array to track visited nodes
    int queue[MAX], front = -1, rear = -1;
    
    // Enqueue the start node
    rear++;
    queue[rear] = start;
    visited[start] = 1;

    printf("BFS traversal starting from node %d:\n", start);

    while (front != rear) {
        // Dequeue the front node
        front++;
        int u = queue[front];

        printf("%d ", u); // Print the current node

        // Explore all adjacent nodes
        for (int v = 0; v < n; v++) {
            if (G[u][v] == 1 && !visited[v]) { // Check if there is an edge and if node v is not visited
                rear++;
                queue[rear] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int G[MAX][MAX], n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("\nEnter the starting node for BFS: ");
    scanf("%d", &start);

    BFS(G, n, start); // Call BFS function

    return 0;
}
