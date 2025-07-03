#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 5000

int degree[MAX_NODES] = {0};
int adj[MAX_NODES][MAX_NODES] = {0};
bool visited[MAX_NODES] = {false};

// Function to perform BFS
void bfs(int starforft, int maxNode) {
    int queue[MAX_NODES], front = 0, rear = 0,start;
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];
        for (int i = 0; i <= maxNode; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

// Count connected components
int countComponents(int maxNode) {
    int count = 0;
    for (int i = 0; i <= maxNode; i++) {
        if (!visited[i]) {
            bfs(i, maxNode);
            count++;
        }
    }
    return count;
}

// Compute clustering coefficient for a node
double clusteringCoefficient(int node, int maxNode) {
    int neighbors[MAX_NODES], nCount = 0;
    for (int i = 0; i <= maxNode; i++) {
        if (adj[node][i]) neighbors[nCount++] = i;
    }

    int links = 0;
    for (int i = 0; i < nCount; i++) {
        for (int j = i + 1; j < nCount; j++) {
            if (adj[neighbors[i]][neighbors[j]]) links++;
        }
    }

    if (nCount < 2) return 0.0;
    return (2.0 * links) / (nCount * (nCount - 1));
}

int main() {
    FILE *file = fopen("facebook_combined.txt", "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    int u, v;
    int edgeCount = 0;
    int maxNode = 0;

    // Reading edges and building adjacency matrix
    while (fscanf(file, "%d %d", &u, &v) != EOF) {
        degree[u]++;
        degree[v]++;
        adj[u][v] = 1;
        adj[v][u] = 1;
        edgeCount++;
        if (u > maxNode) maxNode = u;
        if (v > maxNode) maxNode = v;
    }
    fclose(file);

    // Basic stats
    printf("Total Nodes: %d\n", maxNode + 1);
    printf("Total Edges: %d\n", edgeCount);
    printf("Average Degree: %.2f\n", (2.0 * edgeCount) / (maxNode + 1));

    // Node with highest degree
    int maxDeg = 0, maxDegNode = 0;
    for (int i = 0; i <= maxNode; i++) {
        if (degree[i] > maxDeg) {
            maxDeg = degree[i];
            maxDegNode = i;
        }
    }
    printf("Node with Highest Degree: %d (Degree = %d)\n", maxDegNode, maxDeg);

    // Isolated nodes
    int isolated = 0;
    for (int i = 0; i <= maxNode; i++) {
        if (degree[i] == 0) isolated++;
    }
    printf("Isolated Nodes: %d\n", isolated);

    // Degree distribution
    int degDist[MAX_NODES] = {0};
    for (int i = 0; i <= maxNode; i++) {
        degDist[degree[i]]++;
    }
    printf("\nDegree Distribution:\n");
    for (int i = 1; i < MAX_NODES; i++) {
        if (degDist[i] > 0)
            printf("Degree %d: %d nodes\n", i, degDist[i]);
    }

    // Connected components
    int components = countComponents(maxNode);
    printf("\nConnected Components: %d\n", components);

    // Clustering coefficient of node 0
    double c0 = clusteringCoefficient(0, maxNode);
    printf("Clustering Coefficient of Node 0: %.4f\n", c0);

    return 0;
}
