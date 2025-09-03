#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct Node {
    char val;
    struct Node* next;
};


struct Node* createStack() {
    return NULL; 
}

bool isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Node** top) {
    if (isEmpty(*top)) return '\0';

    struct Node* temp = *top;
    char val = temp->val;
    *top = temp->next;
    free(temp);

    return val;
}

char peek(struct Node* top) {
    if (isEmpty(top)) return '\0';
    return top->val;
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    struct Node* stack = createStack();
    int i = 0, k = 0;
    char c;

    while ( (c = infix[i]) != '\0') {
        
        
        if ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9')) 
        {
            postfix[k++] = c;
        }

        
        else if (c == '(') {
            push(&stack, c);
        }

        
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); 
        }

        
        else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(c)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, c);
        }

        i++;
    }

    
    while (!isEmpty(stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0'; 
}


int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
