
#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node *next;

};

struct Node * createList(){

    struct Node *node;

    node = (struct Node * )malloc(sizeof(struct Node));
    
    node->next = NULL;
    //node -> pointer to struct
    return node;
}

void insert(struct Node *head , int insertVal){
    struct Node * temp;
    temp = head;
    if(temp->next == NULL && !temp->data){
        temp->data = insertVal;
    }
    else{
        
    }
}

void displayList(struct Node *head){
    struct Node * temp;
    temp = head;
    while(temp != NULL){
        printf("%d -> " , temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main(){

    
    struct Node * headnode;

    headnode = createList();
    insert(headnode , 1);
    displayList(headnode);
    
    free(headnode);

    return 0;
}


