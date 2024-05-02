#include "sort.h"
/**
  * quick_sort - quicksort algorithm
  * @array: array to be sorted
  * @size: size of array
  */
void quicks(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort(array, 0, size - 1, size);
}

/**
  * sort_alg - recursive sorting algorithm
  * @arr: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full size of array
  */
void quick_sort(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right, size);
		quick_sort(arr, left, pivot - 1, size);
		quick_sort(arr, pivot + 1, right, size);
	}
}

/**
  * partition - split array
  * @arr: array
  * @left: leftmost element
  * @right: rightmost element
  * @size: full array size
  * Return: pivot index
  */
int partition(int *arr, int left, int right, size_t size)
{
	int i, j, pivot, tmp;
	pivot = arr[right];
	i = left;

	for (j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			if (i != j)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[right])
	{
		tmp = arr[i];
		arr[i] = arr[right];
		arr[right] = tmp;
		print_array(arr, size);
	}

	return (i);
}
