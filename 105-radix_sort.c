#include "sort.h"


/**
 * counting_sort_radix - Counting sort for a specific digit of numbers in array
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @exp: The current significant digit to sort on
 */

void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	/* Count occurrences of digits at the current significant position */
	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	/* Calculate cumulative count */
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	/* Build the output array */
	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}


/**
 * radix_sort - Sorts array of integers in ascending order using LSD radix sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max = array[0];/*Find the maximum element in the array*/
	size_t i;
	int exp;

	if (size < 2)
		return;

	/*Find the maximum element in the array*/
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/*Perform counting sort for every digit from least to most significant*/
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);/*Print the array after each significant digit*/
	}
}
