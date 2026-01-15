#include <stdio.h>
#include <stdlib.h>

#define nVertices 3

int queue[nVertices];
int visited[nVertices];
int front = 0;
int rear = 0;

void displayMatrix(int matrix[nVertices][nVertices]){

    for(int i = 0; i < nVertices ; i++){
        for(int j = 0; j < nVertices ; j++){
            printf("%d " , matrix[i][j]);

        }

        printf("\n");
    }
}


void enqueue(int queueElement){

    queue[rear] = queueElement;
    rear =( rear + 1) % nVertices;

}

int dequeue(){

    int temp = queue[front];

    front =( front + 1) % nVertices;
    return temp;

}

int peek(){
    return queue[front];
}

int isEmpty(){
    if(front-1 == rear){
        return 1;
    }
    return 0;
}


void bfs(int adjMatrix[nVertices][nVertices]){
    //start elemetn
    enqueue(1);

    int temp;
    printf("\n");
    while(isEmpty() == 0){
        temp = dequeue();
        printf("%d ", temp);
        visited[temp] = 1;
        for(int i = 0; i < nVertices; i++){
            if(visited[i] == 0 && adjMatrix[temp][i] == 1){
                enqueue(i);
            }
        }
    }
    printf("\n");

}


int main(){

    int adjMatrix[nVertices][nVertices];

    printf("enter adj matrix: \n");

    for(int i = 0; i < nVertices ; i++){
        visited[i] = 0;
        for(int j = 0; j < nVertices ; j++){
            scanf("%d" , &adjMatrix[i][j]);
        }
    }

    displayMatrix(adjMatrix);

    bfs(adjMatrix);
    return 0;
}
