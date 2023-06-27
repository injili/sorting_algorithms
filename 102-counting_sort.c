#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - a function implementing an integer sorting algorithm
 *
 * @array: an array passed to the function containing numbers >= 0
 * @size: size of the array passed
 *
 * Return: no return value
 */

void counting_sort(int *array, size_t size)
{
	int max = array[0], *count, k, j, *sorted;
	size_t i;

	if (array == NULL || size == 0)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	max += 1;

	count = malloc(sizeof(int) * max);
	if (count == NULL)
		return;

	for (k = 0; k < max; k++)
		count[k] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j < max; j++)
		count[j] += count[j - 1];

	print_array(count, max);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}

	for (i = size - 1; i > 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for(i = 0; i < size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
