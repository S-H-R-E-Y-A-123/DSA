#include <stdio.h>

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Merge function to combine two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // size of the left half is determined by how many elements lie between left and mid, inclusive.
    int n2 = right - mid; 
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j]; 
        j++;
        k++;
    }
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array around the pivot
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function with middle pivot
int partition(int arr[], int low, int high) {
    // Choose the middle element as pivot
    int mid = low + (high - low) / 2; // Avoid overflow for large values of low and high
    int pivot = arr[mid];

    // Move the pivot to the end temporarily
    int temp = arr[mid];
    arr[mid] = arr[high];
    arr[high] = temp;

    int i = (low - 1); // Index of smaller element

    // Partition the array
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Move the pivot to its correct position
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
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
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        mergeSort(arr, 0, n - 1);
        printf("Array sorted using Merge Sort:\n");
    } else if (choice == 2) {
        quickSort(arr, 0, n - 1);
        printf("Array sorted using Quick Sort:\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printArray(arr, n);

    return 0;
}