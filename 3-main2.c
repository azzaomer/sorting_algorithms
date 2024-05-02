#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main() {
    int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    quicksort(arr, 0, size - 1, size);

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}
