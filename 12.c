//DIJKSTRAS ALORITHM 

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999 // Used to represent large distances between nodes (no direct connection).
#define MAX 10 // Max number of vertices in the graph

void dijkstra(int G[MAX][MAX], int n, int startnode); 

int main(){
    int G[MAX][MAX], i, j, n, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n); // n is the number of vertices

    printf("\nEnter the adjacency matrix: \n");
    for (i = 0; i < n; i++){ 
        for (j = 0; j < n; j++){
            scanf("%d", &G[i][j]); // 2D array for the adjacency matrix 
        }
    }

    printf("\nEnter the starting node (0 to %d): ", n - 1);
    scanf("%d", &u); //u is starting node

    if (u < 0 || u >= n) { // If uC(starting node) is greater than the number of vertices defined or smaller than 0
        printf("Invalid starting node\n");
        return 1;
    }

    dijkstra(G, n, u); // Function call for Dijkstra algorithm
    return 0;
}    

void dijkstra(int G[MAX][MAX], int n, int startnode){
    int cost[MAX][MAX], distance[MAX], pred[MAX]; // pred: stores predecessor of each node in the shortest path
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Create the edge weight (cost) matrix
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cost[i][j] = G[i][j];
        }
    }

    // Initialize pred[], distance[], and visited[]
    for (i = 0; i < n; i++){
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n) { // Main while loop to process all nodes
        mindistance = INFINITY;
        nextnode = -1; 

        for (i = 0; i < n; i++){ // Find the node with the minimum distance
            if (distance[i] < mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i; //Set nextnode to i 
            }
        }
        if (nextnode == -1) break; //No unvisited nodes left 

        visited[nextnode] = 1; //Mark the chosen node as visited

        for (i = 0; i < n; i++) { //Update distance values of adjacent nodes
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) { // Checking if path through nextnode offers a shorter path to node i
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;  //Update the predecessor of node i
                }
            }
        }
        count++;  //Increment count to process the next node
    }

    //Print the shortest path and distance to each node
    for (i = 0; i < n; i++){ 
        if (i != startnode){
            printf("\nDistance to node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;

            //Reconstruct the path
            while (j != startnode) {
                j = pred[j]; // pred[] stores the predecessor (or parent) of each node in the shortest path tree
                printf("<-%d", j);
            }
        }
    }
}