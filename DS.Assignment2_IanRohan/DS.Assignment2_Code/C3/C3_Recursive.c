#include <stdio.h>
#include <time.h>

// Ian Rohan
// usm404
// 2/11/2024

void binarySearch(int elements[], int target, int low, int mid, int high) {
    while (low <= high) {
        if (elements[mid] < target) {
            low = mid + 1;
            binarySearch(elements, target, low, mid, high);
        }
        else if (elements[mid] == target) {
            printf("Element found at index %d.", mid);
            break;
        }
        else
          high = mid - 1;
        mid = (low + high) / 2;
        binarySearch(elements, target, low, mid, high);
    }
    if (low > high) {
        printf("Element not found in index.");
    }
}


int main() {
    int target = 8;
    int elements[5];
    int low = 0;
    int high = 5 - 1;
    int mid = (low + high) / 2;
    clock_t start_t, end_t;
    double total_t;
    elements[0] = 5;
    elements[1] = 6;
    elements[2] = 8;
    elements[3] = 9;
    elements[4] = 10;

    start_t = clock();
    printf("Rohan, usm404\n");
    printf("Binary Search (Recursive approach)\n");
    printf("Enter 5 elements:\n");
    
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", elements[i]);
    }

    printf("Enter key element to search:\n");
    printf("%d\n", target);
    
    binarySearch(elements, target, low, mid, high);
    
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTotal time taken by CPU: %f", total_t);

    return 0;
}