#include <stdio.h>
#include <stdlib.h>

// Ian Rohan
// usm404
// 3/20/2024


typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    pq->front = NULL;
    return pq;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (pq->front == NULL || pq->front->priority < priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    }
    else {
        Node* current = pq->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return data;
}

void displayQueue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }
    Node* current = pq->front;
    while (current != NULL) {
        printf("(Element: %d,Priority: %d) \n", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}


int main() {
    PriorityQueue* pq = createPriorityQueue();
    int queueLength, queueElement, queuePriority, userInput;
   
    printf("Ian Rohan, usm404 (Spring 2024)\n");
    
    // Ask user for queue length
    printf("Priority Range: 5 = Highest, 1 = Lowest\n");
    printf("Enter Priority Queue Length: ");
    scanf_s("%d", &queueLength);
    
    // Take user inputs and add into queue
    for (int i = 0; i < queueLength; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf_s("%d", &queueElement);
        printf("Designate Element %d Priority (1 - 5): ", i + 1);
        scanf_s("%d", &queuePriority);
        enqueue(pq, queueElement, queuePriority);
    }

    // Once queue is full, display current queue
    printf("-- Priority Queue Full --\n");
    printf("Displaying Before Dequeue \n");
    displayQueue(pq);

    // Ask user if they want to dequeue, if not, exit
    do {
        printf("-- Would You Like to Dequeue? (1 for yes, any other input for exit) -- ");
        scanf_s("%d", &userInput);
        if (userInput == 1) {
            printf("Dequeue Element: %d\n", dequeue(pq));
            printf("Displaying New Queue\n");
            displayQueue(pq);
        }
    } while (userInput == 1);
    


   
   // printf("Dequeue: %d\n", dequeue(pq));



    free(pq);

    return 0;
}
