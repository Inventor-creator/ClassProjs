#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct node {
    char val;
    struct node *next;
};
struct node *head;
void createhead(){
head=NULL;
}
void insert(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val=x;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return ;
    }
    newnode->next=head;
    head=newnode;
}

char pop(){
    struct node *temp;
    temp=head;
    head=head->next;
    return temp->val;

}
void display(){
    struct node *temp =head;
    while(temp!=NULL){
        printf("%c ",temp->val);
        temp=temp->next;
    }
}
int ordercheck(char x){
    if(x=='^'){
        return 3;
    }else if(x=='/'||x=='*'){
        return 2;
    }else if(x=='+'||x=='-'){
        return 1;
    }else{
        return -1;
    }
}
bool isempty(){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}
char top(){
    return head->val;
}
void convert(char infix[],char postfix[]){
    int i=0;
    int j=0;
    char input;
    while(infix[i]!='\0'){
        input=infix[i];
        if(input>='A' && input<='Z'){
            postfix[j++]=input;
        }else if(input=='('){
            insert(input);
        }else if(input==')'){
            while(!isempty() && top()!='('){
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(!isempty() && ordercheck(top())>=ordercheck(input)){
                postfix[j++]=pop();
            }
            insert(input);
        }
        i++;
    }
    while(!isempty()){
        postfix[j++]=pop();
    }
}
int main(){
    createhead();
    char infix[] = "(A+B)*(C-D)";
    char postfix[100];
    convert(infix,postfix);
    printf("%s",postfix);
    return 0;
}