#include <stdio.h>
#include <stdlib.h>

#define nodes 4

int visited[nodes];

int stack[nodes] = {};

int adjMatrix[nodes][nodes]= {
        {0, 1, 1, 0}, 
        {0, 0, 1, 0}, 
        {1, 0, 0, 1}, 
        {0, 0, 0, 1}  
};


int allVisited(){
    for(int i = 0 ; i < nodes ; i++){
        if(!visited[i]){
            return 0;
        }
    }
    return 1;
}

int top = 0 ;
int pushStack(int i){
    
    top++;

    visited[top] = i;

    return top;
}

int popStack(){
    stack[top] = -1;
    top--;
    return top;
}


void bfs(int node){
    printf("visited %d \n" , node);
    visited[node] = 1;


    for(int i = 0; i < nodes ; i++){
        
        if(adjMatrix[node][i] && !visited[i]){
            visited[i] = 1;
            pushStack(i);
            
        }

    } 

    for(int i = (nodes -1); i > -1; i--){
        popStack();

        bfs(stack[i]);
    }

}

void dfs(int Node ){
    printf("visited %d \n" , Node);
    visited[Node] = 1;
    printf("Visited list: ");

    for(int i =0 ; i < nodes ; i++){
        printf("%d " , visited[i]);

    }
    printf("\n");
    for(int i = 0; i < nodes ; i++){

        if(adjMatrix[Node][i] && !visited[i]){
            dfs(i);
        }
    }   
    
    return;
}

// void dfs(int node) {
//     printf("%d\n", node);
//     visited[node] = 1;
//     for (int i = 0; i < nodes; i++) {
//         if (adjMatrix[node][i] && !visited[i]) {
//             dfs(i);
//         }
//     }
// }


int main(){

    for (int i = 0; i < nodes; i++){
        visited[i] = 0;
    }

    
    dfs(2);
    




    return 0;
}

