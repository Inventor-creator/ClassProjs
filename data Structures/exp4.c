#include <stdio.h>
#include <stdlib.h>

struct queueNode{
    int value;
    struct queueNode* next;
};

void freeQueue(struct queueNode* start){
    struct queueNode* temp = start;
    struct queueNode* temp2;
    while(temp !=  NULL){
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    printf("Freed List \n");
}

struct queueNode* createList(){
    struct queueNode * temp = (struct queueNode *)malloc(sizeof(struct queueNode));
    temp->value = 0;
    temp->next = NULL;
    return temp;
}

void enqueue(struct queueNode* start , int insertVal){
    struct queueNode * temp2;
    if(start->value == 0 && start->next == NULL){ 
        start->value = insertVal;
        start->next = NULL;
    }
    else{
        struct queueNode* temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp2  = (struct queueNode *)malloc(sizeof(struct queueNode));
        temp->next = temp2;
        temp2->value = insertVal;
        temp2->next = NULL;
    }
}

void displayElements(struct queueNode* start){
    struct queueNode* temp = start;
    while(temp != NULL){
        printf("%d \n" , temp->value);
        temp = temp->next;
    }
}

int displayRear(struct queueNode* start){
    struct queueNode * temp; 
    temp = start;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->value;
}

int displayFront(struct queueNode* start){
    return start->value;
}

int dequeue(struct queueNode** start){
    struct queueNode * temp;
    int val;
    if((*start)->next){
        temp = *start;
        val = temp->value;
        *start = (*start)->next;
        free(temp);
    }
    else{
        val = (*start)->value;
        (*start)->value = 0;
    }
    return val;
}

int main(){
    struct queueNode* queue1 = createList();
    int flag = 1;
    int inpVal;
    int temp;
    while(flag){
        printf("Enter waht u want to do: \n1:Queue an element\n2:Dequeue the front element\n3:Display front of queue\n4:Display Rear of queue\n5:Display the entire queue\n6:Exit\n");
        scanf("%d" , &inpVal);
        switch (inpVal)
        {
            case 1:
                printf("Enter an element: ");
                scanf("%d" , &temp);
                enqueue(queue1 , temp);
                break;
            case 2:
                printf("Dequeued %d\n" , dequeue(&queue1) );
                break;
            case 3:
                printf("The front of the queue is: %d \n" , displayFront(queue1));
                break;
            case 4:
                printf("The rear of the queue is: %d \n" , displayRear(queue1));
                break;
            case 5:
                printf("\n");
                displayElements(queue1);
                break;
            case 6:
                flag = 0;
                break;
            default:
                printf("Enter a valid input \n");
                break;
        }
    }
    freeQueue(queue1);
    return 0;
}
