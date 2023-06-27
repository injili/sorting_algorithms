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
	int max, i, k, cnt;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	max++;

	size_t *count_array = malloc(sizeof(int) * max);

	for (k = 0; k < max; k++)
	{
		cnt = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] == k)
				cnt++;
		}
		count[k] = cnt;
	}

	for (j = 1; j < max; j++)
	{
		count[j] = count[j - 1] + count[j]
	}
}
