#include "sort.h"

/**
 *swap - swap elements of array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @i: index
 * @j: size of the array to run
 */
void heapify(int *array, size_t size, int i, int j)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < j && array[left] > array[largest])
		largest = left;

	if (right < j && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, j);
	}
}

/**
 * heap_sort - a function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		heapify(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
