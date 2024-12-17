#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
}    

// Function for Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

// Main Function
int main() {
    int choice, n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    printf("Choose the search technique:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    int result = -1;
    if (choice == 1) {
        result = linearSearch(arr, n, target);
    } else if (choice == 2) {
        printf("Ensure the array is sorted for Binary Search.\n");
        result = binarySearch(arr, 0, n - 1, target);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
