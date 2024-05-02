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
	quick_alg(array, 0, size - 1, size);
}

/**
  * quick_alg - recursive sorting algorithm
  * @array: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full size of array
  */
void quick_alg(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		quick_alg(array, left, pivot - 1, size);
		quick_alg(array, pivot + 1, right, size);
	}
}

/**
  * partition - partition array
  * @array: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full array size
  * Return: pivot index
  */
int partition(int *array, int left, int right, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[right];
	i = left;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[right])
	{
		tmp = array[i];
		array[i] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i);
}
