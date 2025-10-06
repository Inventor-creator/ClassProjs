#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasvisited(int * visited[3]){



    return false;
}


void bfsSearch(int* adjacency[3][3]){
    
    int numNodes = sizeof( *adjacency) / sizeof(*adjacency[0]);
    int visited[numNodes];
    //popuilated the visited array
    for(int i = 0; i < numNodes ; i ++){
        visited[i] = 0;
    }

    int currentNode = 0;

    for(int i = 0 ; i < sizeof(*adjacency[currentNode]) / sizeof(*adjacency[currentNode][0] ) ; i++ ){

        if(*adjacency[currentNode][i] == 1){
            
        }

    }
    

    

}

int main(){

    int adjacency[3][3] = {
        {0,1,1},
        {1,0,1},
        {1,1,0}
    };

    bfsSearch(&adjacency);

    return 0;
}


