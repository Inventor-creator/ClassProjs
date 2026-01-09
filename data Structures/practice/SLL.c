#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;

};

// struct Node* createList(){
//     struct Node* temp;
//     temp = (struct Node *)malloc(sizeof(struct Node));

//     temp->next = NULL;
//     return temp;
// }

struct Node* createList(){
   
    return NULL;
}

void freeList(struct Node* head){
    struct Node* temp;
    temp = head;

    if(temp){
        freeList(temp->next);
    }
    else{
        free(temp);
        printf("freeing \n");
        return ;
    }
}

// void insertEnd(struct Node** head , int insertVal){
//     struct Node*temp;
//     struct Node* newNode;
//     temp = *head;
//     if(!((*head)->val != 0 || (*head)->val) && (*head)->next == NULL){
        
//         printf("here, %d \n",insertVal);

//         (*head)->val = insertVal;
//         return;
//     }
//     else{

        
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         printf("down here, %d \n",  temp->val );

//         newNode = (struct Node *)malloc(sizeof(struct Node));
        
//         newNode->next = NULL;
//         newNode->val = insertVal;
        
//         temp->next = newNode;

//         return;
//     }
// }

struct Node* revList(struct Node* head){

    struct Node* newHead;
    if(head->next == NULL){        
        
        return head;
    }
    else{
        
        newHead = revList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

  
    // struct Node *newhead;
    // if(head->next == NULL){
    //     return head;
    // }
    // else{
    //     newhead = revList(temp->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return newhead;
    // }

}

void insertEnd(struct Node** head, int insertVal) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = insertVal;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;

        return;
    }
    else{
    
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void delEnd(struct Node* head ){
    if(head->next == NULL){ 
        free(head);
        return;
    }
    else if(head->next->next == NULL){
        delEnd(head->next);
        head->next = NULL;
        return;
    }
    else{
        delEnd(head->next);
    }
}



void displayList(struct Node* head){
    if(head){
        printf("%d \n" , head->val);  
        displayList(head->next);
    }
    else{
        return;
    }
}

int main(){

    struct Node* head= createList();
    printf("node created \n");

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    // delEnd(head);
    // insertEnd(head, 1);
    // displayList(head);
    // insertEnd(head, 2);
    // head = revList(head);
    displayList(head);
    freeList(head);



    return 0;
}

