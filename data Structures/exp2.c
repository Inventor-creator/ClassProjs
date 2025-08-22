
#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data ;
    struct Node *next;

};

void insertBegin(struct Node *head  , int insertVal){



    head->data = insertVal;

    
   

}

struct Node*  createSLL(){

    struct Node* newnode;

    newnode = (struct Node * )malloc(sizeof(struct Node));
    
    newnode->data = 0;
    newnode->next = NULL;

    return newnode;
}

void displayList(struct Node *head){
    struct Node *temp = head;


    while(temp != NULL ){
        printf("%d -> " , temp->data);
        temp = temp->next;
    }
    printf("\n");


}

void insertList(struct Node *head ,int newElement , int existingElement){
    struct Node * temp = head;
   
    while(temp != NULL){

        
        if(temp->data == existingElement){
            struct Node *newNode;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = newElement;
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

}

int deleteBefore(struct Node *head , int existingElement){
    struct Node * temp = head;
    struct Node * temp2;
    


    while(temp->next->data != existingElement){
        temp2 = temp;
        temp = temp->next;
    }
    if(temp->next->data == existingElement){
        temp2->next = temp2->next->next;
        int returnData = temp->data;
        free(temp);
        return returnData;
    }
    else{
        printf("Element dosent exist \n");
        return 266;
    }
}


void freeNodeList(struct Node *head){
    struct Node *temp = head;
    struct Node *temp2;
    while(temp != NULL ){
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}

//recursive implementation
struct Node * revList(struct Node * node){
    struct Node *temp = node;
    struct Node *newhead;
    if(temp->next == NULL){
        return temp;
    }
    else{
        newhead = revList(temp->next);
        temp->next->next = temp;
        temp->next = NULL;
        return newhead;
    }

}

int main(){

    int numberLists;

    printf("Enter the amount of linked lists you want to create: ");
    scanf("%d" , &numberLists );

    struct Node *Lists[numberLists];
    for(int i = 0; i < numberLists ; i++){
        Lists[i] = createSLL();
    }

    int choice = 0;
    int counter = 0;
    int flag  =0 ;
    int listChoice = 0;
    int insertVal = 0;
    int insertWhere = 0;
    while(1){

        printf("Enter what you want to do:\n1:Insert into List\n2:Insert at beginning\n3:displayList\n4:Delete before element\n5:Exit\n6:RevList\n");
        scanf("%d" , &choice);
        switch(choice){
            case 1:

                printf("Enter which list you want to insert into:  ");
                scanf("%d" , &listChoice);
                listChoice--;
                
                if(listChoice < numberLists){
                    printf("Enter insert value: ");
                    scanf("%d" , &insertVal);
                    printf("Enter where to insert value: ");
                    scanf("%d" , &insertWhere);
                    insertList(Lists[listChoice],insertVal,insertWhere);
                }
                else{
                   printf("Out of range! \n");
                }

                break;
            case 2:
                //insert at beginenning of list 
                printf("Enter which list you want to insert into:  ");
                scanf("%d" , &listChoice);
                listChoice--;
                if(listChoice < numberLists){
                    printf("Enter insert value: ");
                    scanf("%d" , &insertVal);
                    insertBegin(Lists[listChoice] , insertVal);
                    
                }
                else{
                    printf("Out of range! \n");
                }
                
                break;
            case 3:
                
                printf("Enter which list you want to display :  ");
                scanf("%d" , &listChoice);
                listChoice--;

                if(listChoice < numberLists){
                    displayList(Lists[listChoice]);
                }
                else{
                    printf("Out of range! \n");
                }

                break;
            
            case 4:
                
                printf("Enter which list you want to display :  ");
                scanf("%d" , &listChoice);
                listChoice--;

                if(listChoice < numberLists){
                    //delete here
                    int deleteBeforeEle;
                    printf("Enter beofre which element u want to delete: ");
                    scanf("%d" , &deleteBeforeEle);

                    printf("Deleted %d\n" , deleteBefore(Lists[listChoice] , deleteBeforeEle));

                }
                else{
                    printf("Out of range! \n");
                }

                break;
            case 5:
                for(int i =0 ; i < numberLists ; i++){
                    freeNodeList(Lists[i]);

                }
                flag = 1;
                break;
            case 6:
                printf("Enter which list you want to display :  ");
                scanf("%d" , &listChoice);
                listChoice--;

                if(listChoice < numberLists){
                    //delete here
                    
                    printf("Reversing list ");
                    

                    Lists[listChoice] = revList(Lists[listChoice] );
                    displayList(Lists[listChoice]);

                }
                else{
                    printf("Out of range! \n");
                }
                break;
            default:
                printf("Wrong input given \n");
                break;
        }

        if(flag){
            break;
        }
        printf("\n");
    }
    
    return 0;
}


