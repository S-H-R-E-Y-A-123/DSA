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

// Function for Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {   //i starts from second element
        int key = arr[i]; //current element being sorted
        int j = i - 1; //element before i
        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position

        while (j >= 0 && arr[j] > key) { //while the value before key is greater than key, swap
            arr[j + 1] = arr[j]; //j=i and we set it as the element before i
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    printf("2. Insertion Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        bubbleSort(arr, n);
        printf("Array sorted using Bubble Sort:\n");
    } else if (choice == 2) {
        insertionSort(arr, n);
        printf("Array sorted using Insertion Sort:\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printArray(arr, n);

    return 0;
}
