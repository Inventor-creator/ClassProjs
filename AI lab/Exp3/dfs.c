#include <stdio.h>

void dfs(int adjMatrix[7][7], int visited[7], int node){
    visited[node] = 1;
    printf("%d " , node);

    for (int i = 0; i < 7; i++){
        if (adjMatrix[node][i] == 1 && visited[i] == 0){
            dfs(adjMatrix, visited, i);
        }
    }

}

int main(){

    int adjMatrix[7][7] = {
            {0, 1, 1, 0, 0, 0, 0},
            {1, 0, 0, 1, 1, 0, 0},
            {1, 0, 0, 0, 0, 1, 1},
            {0, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0}
        };

    int visited[7];

    for (int i = 0 ; i < 7; i++){
        visited[i] = 0;
    }

    dfs(adjMatrix, visited, 0);
    printf("\n");
    return 0;
}
