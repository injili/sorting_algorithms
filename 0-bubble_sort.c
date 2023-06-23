#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - a function that sort an array of
 * integers in ascending order using the Bubble sort algorithm
 *
 * @array: array passed to the function
 * @size: size of the array
 *
 * Return: no return value
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swap;
	size_t i, j;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
