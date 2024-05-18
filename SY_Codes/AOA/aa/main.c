#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0; // Index of left subarray
    int j = 0; // Index of right subarray
    int k = 0; // Index of merged array

    // Compare elements from left and right subarrays and merge them in sorted order
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray
    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray
    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void merge_sort(int arr[], int size) {
    // Base case: If the array contains only one element, it is already sorted
    if (size <= 1) {
        return;
    }

    int mid = size / 2; // Middle index of the array

    // Divide the array into two subarrays
    int left[mid];
    int right[size - mid];

    // Copy elements to the left subarray
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    // Copy elements to the right subarray
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the left and right subarrays
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted subarrays
    merge(arr, left, mid, right, size - mid);
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements before sorting:\n");
    print_array(arr, size);

    merge_sort(arr, size);

    printf("Elements after sorting:\n");
    print_array(arr, size);

    return 0;
}
