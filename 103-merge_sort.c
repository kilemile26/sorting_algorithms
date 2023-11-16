#include "sort.h"


/**
 * merge - Merges two subarrays of the original array
 * @array: Pointer to the original array
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 * @size_l: Size of the left subarray
 * @size_r: Size of the right subarray
 */

void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_l + size_r) * sizeof(int));

	if (!temp)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);

	while (i < size_l && j < size_r)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < size_l)
		temp[k++] = left[i++];

	while (j < size_r)
		temp[k++] = right[j++];

	for (i = 0, k = 0; i < size_l + size_r; i++)
		array[i] = temp[k++];

	printf("[Done]: ");
	print_array(array, size_l + size_r);

	free(temp);
}



/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: Pointer to the array
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	int *left = array;
	int *right = array + mid;
	size_t size_l = mid;
	size_t size_r = size - mid;

	if (size < 2 || !array)
		return;

	merge_sort(left, size_l);
	merge_sort(right, size_r);
	merge(array, left, right, size_l, size_r);
}
