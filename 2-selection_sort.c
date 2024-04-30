#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_id, swap, flag = 0;
	
	if (array == NULL)
		return;
	for(i = 0; i < size; i++)
	{
		/* Find the minimum element
		 * in unsorted array
		 */
		min_id = i;
		flag = 0;
		for(j = i + 1; j < size; j++){
		{
			if(array[j] < array[min_id])
			{
				min_id = j;
				flag += 1;
			}
		}
		
		swap = array[i];
		array[i] = array[min_id];
		array[min_id] = swap;
		if (flag != 0)
			print_array(array, size);
	}
	}
}


