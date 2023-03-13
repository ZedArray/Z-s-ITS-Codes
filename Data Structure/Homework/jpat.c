#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else {
        node->right = insert(node->right, data);
    }
    
    return node;
}

void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    return 0;
}
