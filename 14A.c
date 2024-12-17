//BFS | ADJCENCY LIST

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of vertices

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure to hold adjacency list
struct Graph {
    struct Node* adjList[MAX]; // Array of pointers to adjacency list heads
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // For undirected graph, add edge from v to u as well
    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

// Function to perform BFS
void BFS(struct Graph* graph, int n, int start) {
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
        struct Node* temp = graph->adjList[u];
        while (temp) {
            int v = temp->data;
            if (!visited[v]) {
                rear++;
                queue[rear] = v;
                visited[v] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    int n, start;

    // Initialize graph
    for (int i = 0; i < MAX; i++) {
        graph.adjList[i] = NULL;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter edges (u v) for the graph (enter -1 -1 to stop):\n");
    while (1) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1) {
            break;
        }
        addEdge(&graph, u, v);
    }

    printf("\nEnter the starting node for BFS: ");
    scanf("%d", &start);

    BFS(&graph, n, start); // Call BFS function

    return 0;
}
