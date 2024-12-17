// DFS | ADJECENCY LIST

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

// Function to perform DFS (using recursion)
void DFS(struct Graph* graph, int n, int start, int visited[MAX]) {
    visited[start] = 1; // Mark the current node as visited
    printf("%d ", start); // Print the current node

    // Recur for all adjacent nodes
    struct Node* temp = graph->adjList[start];
    while (temp) {
        int v = temp->data;
        if (!visited[v]) {
            DFS(graph, n, v, visited); // Recursive DFS call for unvisited adjacent nodes
        }
        temp = temp->next;
    }
}

int main() {
    struct Graph graph;
    int n, start;
    int visited[MAX] = {0}; // Array to track visited nodes

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

    printf("\nEnter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal starting from node %d:\n", start);
    DFS(&graph, n, start, visited); // Call DFS function

    return 0;
}
