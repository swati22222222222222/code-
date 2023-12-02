#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d \n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int height(struct node* root){
    if(root == NULL){
    return 0;
    }
    else{
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if(leftheight > rightheight){
            return leftheight + 1;
        }
        else{
            return rightheight + 1;
        }

    }
}

int main() {
    struct node* root = NULL;
    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    preorder(root);
    int heightOf = height(root);
    printf("height of tree is %d",heightOf);
    return 0;
}
