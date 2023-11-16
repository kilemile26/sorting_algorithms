#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max;
	size_t v;
	int *count;
	int i;
	int *output;
	ssize_t j;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	max = array[0];
	for (v = 1; v < size; v++)
	{
		if (array[v] > max)
		{
			max = array[v];
		}
	}

	/* Create and initialize the counting array */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	/* Count the occurrences of each element in the array */
	for (v = 0; v < size; v++)
	{
		count[array[v]]++;
	}

	/* Update the counting array to store the cumulative count */
	for (i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	/* Create a temporary array to store the sorted elements */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Build the sorted array */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (v = 0; v < size; v++)
	{
		array[v] = output[v];
	}

	/* Print the counting array */
	printf("%d", count[0]);
	for (i = 1; i <= max; i++)
	{
		printf(", %d", count[i]);
	}
	printf("\n");

	/* Free allocated memory */
	free(count);
	free(output);
}
