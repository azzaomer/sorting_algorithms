#include <stdio.h>
#include "sort.h"

/* Function to swap two integers*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to find the median of three and use it as the pivot*/
int median_of_three(int arr[], int low, int high, size_t size) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
    {
	swap(&arr[low], &arr[mid]);
	print_array(arr, size);
    }
    if (arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
	print_array(arr, size);
    }
    if (arr[mid] > arr[high])
    {
        swap(&arr[mid], &arr[high]);
	print_array(arr, size);
    }
    return arr[mid];
}

/* Partition function for QuickSort*/
int partition(int arr[], int low, int high, size_t size) {
    int pivot = median_of_three(arr, low, high, size);
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* QuickSort function using median of three for partitioning*/
void quicksort(int arr[], int low, int high, size_t size) {
    if (low < high) {
        int pi = partition(arr, low, high, size);
        quicksort(arr, low, pi - 1, size); /*Sort elements before partition*/
        quicksort(arr, pi + 1, high, size); /*Sort elements after partition*/
    }
}
