#include <stdio.h>
#include <stdlib.h>

// Ian Rohan
// 4/7/2024
// usm404

typedef struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Get height of node
int getHeight(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Update height
void updateHeight(AVLNode* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Right rotation
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balance tree
AVLNode* balance(AVLNode* node) {
    if (node == NULL)
        return node;

    updateHeight(node);

    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    // Left heavy
    if (balanceFactor > 1) {
        // Left-left
        if (getHeight(node->left->left) >= getHeight(node->left->right))
            return rotateRight(node);
        // Left-right
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // Right heavy
    else if (balanceFactor < -1) {
        // Right-right 
        if (getHeight(node->right->right) >= getHeight(node->right->left))
            return rotateLeft(node);
        // Right-left
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    return node;
}

// Insert node
AVLNode* insert(AVLNode* root, int key) {
    if (root == NULL) {
        AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else 
        return root;

    // Balance
    return balance(root);
}

// Find min key node
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete key 
AVLNode* deleteNode(AVLNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    

    else {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode* temp = root->left ? root->left : root->right;

        
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy

            free(temp);
        }
        else {
            // Get in order
            AVLNode* temp = minValueNode(root->right);

            // Copy the successor data to this node
            root->key = temp->key;

            // Delete successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If tree had only one node
    if (root == NULL)
        return root;

    // Balance the tree
    return balance(root);
}

// Search for key
void search(AVLNode* root, int key) {
    if (root == NULL) {
        printf("Not Found\n");
        return;
    }
    if (root->key == key) {
        printf("Found\n");
        return;
    }
    if (key < root->key)
        search(root->left, key);
    else
        search(root->right, key);
}

// In order traversal
void inOrderTraversal(AVLNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

// Calculate height
int calculateHeight(AVLNode* root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int main() {
    AVLNode* root = NULL;
    int choice, key;

    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. In-order Traversal\n");
        printf("5. Calculate Height\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf_s("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf_s("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf_s("%d", &key);
            search(root, key);
            break;
        case 4:
            printf("In-order Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Height of AVL tree: %d\n", calculateHeight(root));
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
