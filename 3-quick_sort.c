#include "sort.h"
/**
  * quick_sort - quicksort algorithm
  * @array: array to be sorted
  * @size: size of array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort_alg(array, 0, size - 1, size);
}

/**
  * sort_alg - recursive sorting algorithm
  * @arr: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full size of array
  */
void sort_alg(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = split(arr, left, right, size);
		sort_alg(arr, left, pivot - 1, size);
		sort_alg(arr, pivot + 1, right, size);
	}
}

/**
  * split - split array
  * @arr: array
  * @left: leftmost element
  * @right: rightmost element
  * @size: full array size
  * Return: pivot index
  */
int split(int *arr, int left, int right, size_t size)
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
