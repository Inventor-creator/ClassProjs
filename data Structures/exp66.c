#include <stdio.h>
#define N 10

int adj[N][N];
int visited[N], queue[N];
int n, front = 0, rear = -1;

void bfs(int start) {
    int i, v;
    visited[start] = 1;
    rear += 1;
    queue[rear] = start;

    while (front <= rear) {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                rear += 1;
                queue[rear] = i;
            }
        }
    }
}

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }
}

// mayank is my goat.




int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(start);
    printf("\n");
    printf("DFS traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
