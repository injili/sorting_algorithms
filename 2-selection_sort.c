#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers
 * in ascending order using the Selection Sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array passed
 *
 * Return: no return value
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_int, temp, swap;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_int = i;
		swap = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_int])
			{
				swap = 1;
				min_int = j;
			}
		}

		temp = array[i];
		array[i] = array[min_int];
		array[min_int] = temp;
		if (swap == 1)
			print_array(array, size);
	}
}
