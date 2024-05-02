#include "sort.h"
/**
* swap - swaps the positions of two elements into an array
* @array: array
* @a: array element
* @b: array element
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * median_of_3 - partition sorting scheme implementation
 * @array: array
 * @low: first array element
 * @high: last array elment
 * @size: size of the array
 * Return: the position of the pivot
 */
int median_of_3(int *array, size_t low, size_t high, size_t size)
{
    int pivot = low + (high-low)/2;
    if (array[high] < array[low])
	    swap(low, high);
    if (array[pivot] < array[low])
	    swap(low, pivot);
    if (array[high] < array[pivot])
	    swap(pivot, high);
    print_array(array, size);
    return array[pivot];
}
/**
 * Partition - partition function for quick sort
 * @array: array
 * @low: first element of the array
 * @high: last lment of array
 */
int Partition(int *array, size_t low, size_t high)
{
	int pivot = median_of_3(array, low, high);
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array[i], array[j];
		}
	
	}
	swap(array[i + 1], array[high]);
	return i + 1;
}
/**
 * quicks - qucksort algorithm implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 */
void quicks(int *array, size_t first, size_t last, int size)
{
	size_t position = 0;
	
	if (first < last)
	{
		position = median_of_3(array, first, last, size);
		quicks(array, first, position - 1, size);
		quicks(array, position + 2, last, size);
	}
}
/**
 * quick_sort - prepare the terrain to quicksort algorithm
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicks(array, 0, size - 1, size);
}
