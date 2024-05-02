
#include "sort.h"
/**
  * shell_sort - shell sort, knuth sequence
  * @array: array to be sorted
  * @size: size of array
  */
void shell_sort(int *array, size_t size)
{
	size_t knuth, i, j;
	int tmp;

	knuth = 1;
	while (knuth < size)
		knuth = (knuth * 3) + 1;
	knuth = (knuth - 1) / 3;
	while (knuth > 0)
	{
		for (i = knuth; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= knuth && array[j - knuth] > tmp; j -= knuth)
				array[j] = array[j - knuth];
			array[j] = tmp;
		}
		knuth = (knuth - 1) / 3;
		print_array(array, size);
	}
}
