#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, temp;

	if (array == NULL || size <= 2)
		return;

	while (gap <= (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
