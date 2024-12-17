#include <stdio.h>

// Function for Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function for Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) { //j=i+1 because we dont want to iterate over already sorted part
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex] if current j is > current minIndex
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
}

// Main Function
int main() {
    int n, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose the sorting technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        bubbleSort(arr, n);
        printf("Array sorted using Bubble Sort:\n");
    } else if (choice == 2) {
        selectionSort(arr, n);
        printf("Array sorted using Selection Sort:\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printArray(arr, n);

    return 0;
}
