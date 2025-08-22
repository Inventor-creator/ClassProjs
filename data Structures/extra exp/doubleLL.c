#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct DoubleNode{

    int val;
    struct DoubleNode *next;
    struct DoubleNode *prev;


};

void freeList(struct DoubleNode * head){


    struct DoubleNode *temp = head;
    struct DoubleNode *temp2;
    while(temp != NULL ){
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}
   


void insertBegg(struct DoubleNode * head , int value){
    struct DoubleNode * temp;
    temp = head;
    temp->next = NULL;
    temp->prev = NULL;
    temp->val = value;

}
void insertList(struct DoubleNode * head , int value){
    struct DoubleNode * temp;
    temp = head;
    int flag = 0;

    while( temp->next != NULL ){
        temp = temp->next;

    }


    struct DoubleNode * insertNode = (struct Node * )malloc(sizeof(struct DoubleNode));

    insertNode->next = NULL;
    insertNode->prev = temp;
    temp->next = insertNode;
    insertNode->val = value;


}

void displayList(struct DoubleNode * head){
    struct DoubleNode *temp;
    temp = head;
    printf("printing straight \n");
    while(temp != NULL){
        printf("%d <-> ",temp->val);
        if(temp->next){
        temp = temp->next;
        }else{
            break;
        }
    }
    printf("\nPrinting backwards \n");
    while(temp != NULL){
        printf("%d <-> ",temp->val);
        temp = temp->prev;
        
    }
    printf("\n");
}

void deleteAfter(struct DoubleNode * head , int key){
    struct DoubleNode *temp;
    temp = head;
    
    
    while(temp->val != key && temp != NULL){

        temp = temp->next;
        
    }
    
    if(temp && temp->next){
        temp = temp->next;
        if(temp->next){
            printf("value of node deleting %d" , temp->val);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
        }
        else{
            temp->prev->next = NULL;
            free(temp);

        }
       
    }

}


int main(){

    struct DoubleNode* head = (struct DoubleNode * )malloc(sizeof(struct DoubleNode));
    insertBegg(head , 1);
    displayList(head);
    printf("\n");

    insertList(head, 2);
    displayList(head);
    printf("\n");


    insertList(head, 3);
    displayList(head);
    printf("\n");

    insertList(head, 4);
    displayList(head);
    printf("\n");

    deleteAfter(head , 4);
    displayList(head);
    printf("\n");

    freeList(head);

    return 0;
}


