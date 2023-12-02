#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

struct Node* createMirrorImage(struct Node* root) {
    if (root == NULL) {
        return NULL;
    } else {
        struct Node* temp;
        root->left = createMirrorImage(root->left);
        root->right = createMirrorImage(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
}

void printLeafNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    // Calculate and print the number of nodes
    int noofnodes = countNodes(root);
    printf("Number of nodes in the tree: %d\n", noofnodes);

    // Print inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Print leaf nodes
    printf("Leaf nodes: ");
    printLeafNodes(root);
    printf("\n");

    return 0;
}

