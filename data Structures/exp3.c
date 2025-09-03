#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    char val;
    struct Node* next;
};

struct Node* createStack(){

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = 0;
    newNode->next = NULL;
    return newNode;
}

void Spush(struct Node* head , char pushVal){
    struct Node *temp = head;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    

    newNode->next = temp->next;
    temp->next = newNode;
    temp->next->val = temp->val;
    temp->val = pushVal;
    
    

}

void PStack(struct Node* head){
    struct Node * temp = head;
    while(temp){
        printf("%c \n" ,temp->val);
        temp = temp->next;
    }


}

void Spop(struct Node* head){
    if(head->next != NULL ){
        struct Node* temp = head;
        struct Node* temp2 = head->next;
        temp->val = temp2->val;
        temp->next = temp->next->next;
        free(temp2);
    }
    else{
        printf("Stack is already empty \n");
    }
}

char Speek(struct Node* head){

    return head->val;

}

bool isEmpty(struct Node* head){
    if(head->next){
        return false;

    }
    else{
        return true;
    }
}

void infixToPostfix(char* infix, char* postfix, struct Node* stack) {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            
            postfix[k++] = c;
        }
        else if (c == '(') {
            Spush(stack, c);
        }
        else if (c == ')') {
            while (!isEmpty(stack) && Speek(stack) != '(') {
                postfix[k++] = Speek(stack);
                Spop(stack);
            }
            Spop(stack); 
        }
        else { 
            while (!isEmpty(stack) && precedence(Speek(stack)) >= precedence(c)) {
                postfix[k++] = Speek(stack);
                Spop(stack);
            }
            Spush(stack, c);
        }
    }

    
    while (!isEmpty(stack)) {
        postfix[k++] = Speek(stack);
        Spop(stack);
    }

    postfix[k] = '\0'; 
}


int main(){

    struct Node* stackOne;
    stackOne = createStack();
    bool flag = true;
    int action = -1;
    char actionVal;
    while(flag){

        printf("What do u want to do: \n1:Push into stack\n2:Pop from stack\n3:Peek at top\n4:Check if empty\n5:Exit \n");
        scanf("%d" , &action);
        printf("\n");
        switch (action)
        {
        case 1:
            printf("Enter the value u want to push: ");
            scanf(" %c" , &actionVal);
            Spush(stackOne , actionVal);
            break;
        case 2:
            Spop(stackOne);    

            break;
        case 3:
            printf("top of stack: %c \n",Speek(stackOne));
            break;
        case 4:
            if(isEmpty(stackOne)){
                printf("Stack is empty \n");
            }
            else{
                printf("Stack is not empty \n");
            }
            break;
        case 5:
            flag = false;
            break;
        case 6:
    {
        char infix[100], postfix[100];
        printf("Enter infix expression: ");
        scanf("%s", infix);
        struct Node* exprStack = createStack();
        infixToPostfix(infix, postfix, exprStack);
        printf("Postfix expression: %s\n", postfix);
        
        // free exprStack
        struct Node* tmp;
        while(exprStack->next) {
            tmp = exprStack->next;
            free(exprStack);
            exprStack = tmp;
        }
        free(exprStack);
    }
    break;

        default:
            break;
        }


    }



    struct Node* temp;

    while(stackOne -> next){
        temp = stackOne->next;
        free(stackOne);
        stackOne = temp;
    }

    free(stackOne);

    return 0;
}

