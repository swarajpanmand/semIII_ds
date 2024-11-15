#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node * createNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node ** root, int data){
    if(*root == NULL){
        *root = createNode(data);
        return;
    }

    if(data<(*root)->data){
        insert(&(*root)->left, data);
    }else{
        insert(&(*root)->right, data);
    }
}

void inorder(Node** root){
    if(*root == NULL){
        return;
    }
    inorder(&(*root)->left);
    printf("%d ", (*root)->data);
    inorder(&(*root)->right);
}

void preorder(Node** root){
    if(*root == NULL){
        return;
    }
    printf("%d ", (*root)->data);
    preorder(&(*root)->left);
    preorder(&(*root)->right);
}

void postorder(Node** root){
    if(*root == NULL){
        return;
    }
    postorder(&(*root)->left);
    postorder(&(*root)->right);
    printf("%d ", (*root)->data);
}

int main(){
    Node * root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    printf("Inorder: ");
    inorder(&root);
    printf("\n");
    printf("Preorder: ");
    preorder(&root);
    printf("\n");
    printf("Postorder: ");
    postorder(&root);
    printf("\n");
    return 0;
}