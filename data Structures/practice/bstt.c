// #include<stdlib.h>
// #include<stdio.h>
// #include<stdbool.h>
// struct node{
//     int val;
//     struct node *left;
//     struct node *right;
// };
// struct node *head;
// void createbst(){
// head=NULL;
// }

// void insert(int x){
//     struct node *newnode;
//     newnode=(struct node*)malloc(sizeof(struct node));
//     newnode->val=x;
//     newnode->right=NULL;
//     newnode->left=NULL;
//     if(head==NULL){
//         head = newnode;
//         return;
//     }
//     struct node *temp;
//     temp=head;
//     while(true){
//         if(temp->val<=x){
//             if(temp->right!=NULL){
//                 temp=temp->right;
//             }else{
//                 temp->right=newnode;
//                 break;
//             }
//         }else if(temp->val>x){
//             if(temp->left!=NULL){
//                 temp=temp->left;
//             }else{
//                 temp->left=newnode;
//                 break;
//             }
//         }
//     }
// }

// struct node* helper(struct node *root){
//     if(root->left== NULL){
//         return root->right;
//     }else if(root->right==NULL){
//         return root->left;
//     }
//     struct node *rightchild = root->right;
//     struct node *lastright = findlastright(root->left);
//     lastright->right = rightchild; 
//     return root->left;
// }
// struct node* findlastright(struct node *root){
//     if(root->right==NULL){
//         return root;
//     }
//     return findlastright(root->right);
// }
// struct node* delete(struct node *root , int key){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->val == key){
//         return helper(root);
//     }
//     struct node *temp;
//     temp=root;
//     while(temp!=NULL){
//         if(root->val>key){
//             if(root->left!=NULL && root->left->val == key){
//                 root->left = helper(root->left);
//                 break;
//             }else{
// root=root->left;
//             }
            
//         }else{
//                         if(root->right!=NULL && root->right->val == key){
//                 root->right = helper(root->right);
//                 break;
//             }else{
//   root=root->right;
//             }
          
//         }
//     }
//     return temp;
// }

// void inorder(struct node *headd){
//     struct node *search = headd;
//     if(search==NULL){
//         return ;
//     }
//     inorder(search->left);
//     printf("%d",search->val);
//     inorder(search->right);
// }
// int main(){
//     createbst();
//     insert(5);
//     insert(6);
//     insert(3);
//     insert(4);
//     insert(7);
//     insert(8);
//     insert(2);
//     insert(10);
//     insert(30);
//     insert(15);
//     delete(head,4);
//     // inorder(head);
//     return 0;
// }


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node *head;

void createbst() {
    head = NULL;
}

void insert(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (true) {
        if (temp->val <= x) {
            if (temp->right != NULL) {
                temp = temp->right;
            } else {
                temp->right = newnode;
                break;
            }
        } else {
            if (temp->left != NULL) {
                temp = temp->left;
            } else {
                temp->left = newnode;
                break;
            }
        }
    }
}

/* Forward declarations */
struct node* helper(struct node *root);
struct node* findlastright(struct node *root);

struct node* delete(struct node *root, int key) {
    if (root == NULL) return NULL;

    if (root->val == key) {
        return helper(root);
    }

    struct node *temp = root;
    while (temp != NULL) {
        if (temp->val > key) {
            if (temp->left != NULL && temp->left->val == key) {
                temp->left = helper(temp->left);
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right != NULL && temp->right->val == key) {
                temp->right = helper(temp->right);
                break;
            } else {
                temp = temp->right;
            }
        }
    }
    return root;
}

struct node* helper(struct node *root) {
    if (root->left == NULL) return root->right;
    else if (root->right == NULL) return root->left;

    struct node *rightchild = root->right;
    struct node *lastright = findlastright(root->left);
    lastright->right = rightchild;
    return root->left;
}

struct node* findlastright(struct node *root) {
    if (root->right == NULL) return root;
    return findlastright(root->right);
}

void inorder(struct node *headd) {
    if (headd == NULL) return;
    inorder(headd->left);
    printf("%d ", headd->val);
    inorder(headd->right);
}

int main() {
    createbst();
    insert(5);
    insert(6);
    insert(3);
    insert(4);
    insert(7);
    insert(8);
    insert(2);
    insert(10);
    insert(30);
    insert(15);

    printf("Before deletion: ");
    inorder(head);

    head = delete(head, 4); // ✅ must assign return value

    printf("\nAfter deletion: ");
    inorder(head);

    return 0;
}
