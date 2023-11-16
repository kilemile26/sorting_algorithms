#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursive(array, size, 1);
}



/**
 * bitonic_recursive - Recursive helper function for Bitonic sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @dir: 1 for ascending, 0 for descending
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	/* Sort in ascending order */
	bitonic_recursive(array, mid, 1);
	/* Sort in descending order */
	bitonic_recursive(array + mid, size - mid, 0);
	/* Merge the two halves */
	bitonic_merge(array, size, dir);
}



/**
 * bitonic_merge - Merges two Bitonic sequences
 * @array: Pointer to the array to be merged
 * @size: Size of the array
 * @dir: 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t mid;
	size_t i;

	if (size < 2)
		return;

	mid = size / 2;


	for (i = 0; i < mid; i++)
	{
		if ((array[i] > array[i + mid]) == dir)
			swap(&array[i], &array[i + mid]);
	}

	/* Recursively sort both halves */
	bitonic_merge(array, mid, dir);
	bitonic_merge(array + mid, size - mid, dir);
}



/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
