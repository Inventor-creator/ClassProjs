#include <stdio.h>
#include <stdlib.h>







struct Node{

    int value;
    struct Node* left;
    struct Node* right;

};

struct Node* createNode(){

    struct Node* newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

void freeTree(struct Node *head){

    if( head != NULL){

        freeTree(head->left);
        freeTree(head->right);
        free(head);

    }
    else{
        return;
    }

}

void displayPostOrder(struct Node *head){

    if( head != NULL){

        displayPostOrder(head->left);
        displayPostOrder(head->right);
        printf("%d " , head->value);
        
    }
    else{
        return;
    }

}

void displayInOrder(struct Node *head){

    if( head != NULL){

        displayInOrder(head->left);
        printf("%d " , head->value);
        displayInOrder(head->right);
        
    }
    else{
        return;
    }

}

struct Node* createBst(int value){
    struct Node * newnode;
    newnode = createNode();
    newnode->value = value;
    return newnode;
}

void insert(struct Node * head , int value){
    struct Node* temp;
    temp = head;


    if(head){
        while(1){
            if(value > temp->value && !temp->right){
                temp->right = createNode();
                temp->right->value = value;
                return;
            }
            else if(value < temp->value && !temp->left){
                temp->left = createNode();
                temp->left->value = value;
                return;
            }
            else if(value < temp->value){
                temp = temp->left;
            }
            else if(value > temp->value){
                temp = temp->right;
            }
            else if(value == temp->value){
                printf("value already exists in tree \n");
                return;
            }

        }
    }
}

struct Node* inOrderSucc(struct Node *head){

    head = head->right;
    while (head != NULL && head->left != NULL){
        head = head->left;
    }
    return head;

}


struct Node* searchNode(int value , struct Node* head){
    struct Node * temp;
    temp = head;

    while(temp != NULL){
        if(temp->value > value){
            temp = temp->left;
        }
        else if(temp->value < value){
            temp = temp->right;
        }
        else{
            return temp;
        }
    }
    printf("Node dosent exist \n");
    return NULL;
}

struct Node* delete(struct Node* head , int deleteVal){
    
    if (head->value > deleteVal){
        head->left = delete(head->left, deleteVal);
    }
    else if (head->value < deleteVal){
        head->right = delete(head->right, deleteVal);
    }
    else {
        

        if (head->left == NULL) {
            struct Node* temp = head->right;

            free(head);
            return temp;
        }

        
        if (head->right == NULL) {
            struct Node* temp = head->left;
            free(head);
            return temp;
        }

        
        struct Node* succ = inOrderSucc(head);
        head->value = succ->value;

        head->right = delete(head->right, succ->value);
    }
    return head;
    
   
}

int main(){

    struct Node* bst = NULL;
        
    int choice = 0;

    
    do{
        printf("1. Insert \n");
        printf("2. Display Inorder \n");
        printf("3. Display Postorder \n");
        printf("4. Search \n");
        printf("5. Delete \n");  
        printf("6. Exit \n");
        printf("Enter choice : ");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            int val;
            printf("Enter value to insert : ");
            scanf("%d" , &val);
            if(bst == NULL){
                bst = createBst(val);
                break;
            }
            insert(bst , val);
            break;
        case 2 :
            printf("Inorder display : ");
            displayInOrder(bst);
            printf("\n");
            break;
        case 3 :
            printf("Postorder display : ");
            displayPostOrder(bst);
            printf("\n");
            break;
        case 4 :
            printf("Enter value to search : ");
            int searchVal;
            scanf("%d" , &searchVal);
            struct Node* foundNode = searchNode(searchVal , bst);
            if(foundNode != NULL){
                printf("Node found with value : %d \n" , foundNode->value);
            }else{
                printf("Node not found \n");
            }
            break;
        case 5 :
            printf("Enter value to delete : ");
            int deleteVal;
            scanf("%d" , &deleteVal);

            bst = delete(bst , deleteVal);
            break;
        case 6 :
            choice = 7;
            break;

        default:
            break;
        }

    }while(choice != 7);
    


    freeTree(bst);

    return 0;
}
