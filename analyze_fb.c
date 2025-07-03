#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5000

int main() {
    FILE *file = fopen("facebook_combined.txt", "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    int u, v;
    int degree[MAX_NODES] = {0};
    int maxNode = 0;
    int edgeCount = 0;

    while (fscanf(file, "%d %d", &u, &v) != EOF) {
        degree[u]++;
        degree[v]++;
        edgeCount++;

        if (u > maxNode) maxNode = u;
        if (v > maxNode) maxNode = v;
    }

    fclose(file);

    printf("Total nodes: %d\n", maxNode + 1);
    printf("Total edges: %d\n", edgeCount);

    int maxDegree = 0, maxDegreeNode = 0;
    for (int i = 0; i <= maxNode; i++) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxDegreeNode = i;
        }
    }

    printf("Node with highest degree: %d (degree = %d)\n", maxDegreeNode, maxDegree);

    return 0;
}
