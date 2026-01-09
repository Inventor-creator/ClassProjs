#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;

};

struct Node* createBst(){
    return NULL;
}

void insertTree(struct Node** root , int insertVal){
    struct Node* newNode;

    if(!(*root)){
        
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val =insertVal;
        (*root) = newNode;
        return;
    }

    if(insertVal < (*root)->val && (*root)->left){
        insertTree(&(*root)->left , insertVal);
        return;
    }
    else if(insertVal < (*root)->val && !(*root)->left){
        
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val =insertVal;
        (*root)->left = newNode;
        return;
    }
    else if (insertVal > (*root)->val && (*root)->right){
        insertTree(&(*root)->right , insertVal);
        return;
    }
    else if(insertVal > (*root)->val && !(*root)->right){
        
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val =insertVal;
        (*root)->right = newNode;
        return;
    }
    else if(insertVal == (*root)->val){
        return;
    }

}

struct Node* deleteFromTree(struct Node* root1 , struct Node* root, int delValue){

    if(root){
        if(delValue < root->val){
            root->left =  deleteFromTree(root1 ,root->left ,delValue);
        }
        else if(delValue > root->val){
            root->right = deleteFromTree(root1 , root->right ,delValue);
        }
        else{
            struct Node* temp;
            
            if(!root->left && !root->right){
                free(root);
                return NULL;
            }
            else if(!root->left && root->right){
                temp = root->right;
                free(root);
                return temp;
            }
            else if(root->left && !root->right){
                temp = root->left;
                free(root);
                return temp;
            }
            else{
                temp = root;
                temp = temp->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                int tempval = temp->val;
                temp->val = root->val;
                root->val = tempval;
                deleteFromTree(root1 , root1 , root->val);
                return root;

            }

        }
        
    }
    return root;

}

void freeTree(struct Node* root){
    if(root){
        
        freeTree(root->left);
  
        freeTree(root->right);
        free(root);
        
    }
    
}

void inOrder(struct Node* root){

    if(root){

    
        inOrder(root->left);
        

        printf("%d " , root->val);

        
        inOrder(root->right);
       
      
    }

}

int main(){

    struct Node* newtree = createBst();

    insertTree(&newtree , 2);
    insertTree(&newtree , 4);
    insertTree(&newtree , 3);
    insertTree(&newtree , 1);
    insertTree(&newtree , 12);
    insertTree(&newtree , 7);

    inOrder(newtree);
    
    deleteFromTree(newtree , newtree, 4);
    
    printf("\n");
    inOrder(newtree);
    freeTree(newtree);

    return 0;
}

