#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with Hoare partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	
	hoare_partition(array, 0, size - 1, size);
}

/**
 * hoare_partition - Implements the Hoare partition scheme for Quick sort.
 * @array: The array of integers to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the original array (used for printing).
 */
void hoare_partition(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1, j = high + 1;

		while (1)
		{
			do
			i++;
			while (array[i] < pivot);
			do
			j--;
			while (array[j] > pivot);
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			else
				break;
		}

		hoare_partition(array, low, j, size);
		hoare_partition(array, j + 1, high, size);
	}
}


/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
