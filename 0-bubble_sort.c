#include "sort.h"
/**
 * bubble_sort - sort array ements from min to max value
 * @array: array
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{

        size_t i, j, tmp = 0;

        if (size < 2)
                return;
        for (i = 0; i < size; i++)
                for (index = 0; index < size; index++)
                {
                        if (array[j] > array[j + 1] && array[j + 1])
                        {
                        tmp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = tmp;
                        print_array(array, size);
                        }
                }
}
