#include <stdio.h>
#include <stdlib.h>

// Ian Rohan
// usm404
// 4/7/2023

typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create tree node
TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->key = key;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

// Insert key
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Pre-order traversal
void preOrderBST(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrderBST(root->left);
        preOrderBST(root->right);
    }
}

// Convert BST to AVL
TreeNode* arrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = createNode(arr[mid]);

    root->left = arrayToBST(arr, start, mid - 1);
    root->right = arrayToBST(arr, mid + 1, end);

    return root;
}

// Read size of BST
int getSize(TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

// Store keys in array
void storeBSTKeys(TreeNode* root, int arr[], int* index) {
    if (root == NULL)
        return;
    storeBSTKeys(root->left, arr, index);
    arr[*index] = root->key;
    (*index)++;
    storeBSTKeys(root->right, arr, index);
}

// Balance BST and return AVL root
TreeNode* balanceBST(TreeNode* root) {
    int n = getSize(root);
    int* arr = (int*)malloc(n * sizeof(int));
    int index = 0;

    storeBSTKeys(root, arr, &index);
    return arrayToBST(arr, 0, n - 1);
}

// Pre-order traversal of AVL
void preOrderAVL(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrderAVL(root->left);
        preOrderAVL(root->right);
    }
}

int main() {
    int input[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(input) / sizeof(input[0]);

    TreeNode* rootBST = NULL;
    TreeNode* rootAVL = NULL;

    // Create BST
    for (int i = 0; i < n; i++)
        rootBST = insert(rootBST, input[i]);

    // Print BST pre-order
    printf("BST Pre-order: ");
    preOrderBST(rootBST);
    printf("\n");

    // Balance BST to AVL
    rootAVL = balanceBST(rootBST);

    // Print AVL pre-order
    printf("Balanced-AVL Pre-order: ");
    preOrderAVL(rootAVL);
    printf("\n");

    return 0;
}
