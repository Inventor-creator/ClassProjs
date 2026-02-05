#include <stdio.h>
#include <limits.h>

#define V 5


int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 0; i < V; i++) {


        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }


    return minIndex;
}


void path(int parent[], int j) {
    if (parent[j] == -1)
        return;

    path(parent, parent[j]);
    printf(" -> %d", j);
}


void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    int parent[V];


    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;

        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;


    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] &&

                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }


    printf("Vertex\tDistance\tPath\n");

    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t%d", i, dist[i], src);


        path(parent, i);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
