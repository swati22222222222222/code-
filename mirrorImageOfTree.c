#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void mirrorImage(struct node* root) {
    if (root == NULL)
        return;

    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

void printInorder(struct node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void deleteTree(struct node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int count_leaf(struct node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int left_leaf_count = count_leaf(root->left);
    int right_leaf_count = count_leaf(root->right);

    return left_leaf_count + right_leaf_count;
}
int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);

    printf("Original Tree (Inorder): ");
    printInorder(root);
    printf("\n");

    mirrorImage(root);

    printf("Mirror Image (Inorder): ");
    printInorder(root);
    printf("\n");

    printf("%d",count_leaf(root));

    return 0;
}
