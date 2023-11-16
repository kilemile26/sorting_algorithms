#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Pointer to the array
 * @start: Index of the root element
 * @end: Index of the last element
 * @size: Size of the array
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;

		if (array[root] < array[child])
		{
			int temp = array[root];

			array[root] = array[child];
			array[child] = temp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */

void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; (int)i >= 0; i--)
		sift_down(array, i, size - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
