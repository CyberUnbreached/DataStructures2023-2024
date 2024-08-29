#include <stdio.h>
#define V 5 

// Ian Rohan
// 4/21/24
// usm404

// Initialize tree
void init(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1;
}

// Remove edges
void removeEdge(int arr[][V], int i, int j) {
    arr[i][j] = 0;
    arr[j][i] = 0;
}

// Check if there is an edge between vertices u and v
int isEdge(int arr[][V], int u, int v) {
    return arr[u][v];
}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
    int i, j;

    for (i = 0; i < V; i++) {
        printf("%d: ", i);
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];
    init(adjMatrix);
    int choice, u, v;

    while (1) {
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Check Edge\n");
        printf("4. Print Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: // Adds edge
            printf("Enter vertices (u v) to add edge: ");
            scanf_s("%d %d", &u, &v);
            addEdge(adjMatrix, u, v);
            printf("Edge between vertices %d and %d added.\n", u, v);
            break;
        case 2: // Remove edge
            printf("Enter vertices (u v) to remove edge: ");
            scanf_s("%d %d", &u, &v);
            removeEdge(adjMatrix, u, v);
            printf("Edge between vertices %d and %d removed.\n", u, v);
            break;
        case 3: // Check if efge is present
            printf("Enter vertices (u v) to check edge: ");
            scanf_s("%d %d", &u, &v);
            if (isEdge(adjMatrix, u, v))
                printf("There is an edge between vertices %d and %d\n", u, v);
            else
                printf("There is no edge between vertices %d and %d\n", u, v);
            break;
        case 4:
            printf("Adjacency Matrix:\n");
            printAdjMatrix(adjMatrix);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
