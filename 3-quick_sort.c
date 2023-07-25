#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 *
 * Return: nothing
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - lomuto partition scheme for quicksort
 * @array: Array to be sorted
 * @lower: lower bound of the partition
 * @upper: upper bound of the partition
 * @size: size of the array
 *
 * Return: index of the pivot after partitioning
 */

int lomuto_partition(int *array, int lower, int upper, size_t size)
{
	int pivot = 0, i = lower - 1, j;

	pivot = array[upper];
	for (j = lower; j <= upper - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[upper])
	{
		swap(&array[i + 1], &array[upper]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_aux - recursive function to perform quicksort
 * @array: array to be sorted
 * @lower: lower bound of the partition
 * @upper: upper bound of the partition
 * @size: size of the array
 *
 * Return: nothing
 */
 
void quick_sort_aux(int *array, int lower, int upper, size_t size)
{
	int pivot_idx;

	if (lower < upper)
	{
		pivot_idx = lomuto_partition(array, lower, upper, size);
		quick_sort_aux(array, lower, pivot_idx - 1, size);
		quick_sort_aux(array, pivot_idx + 1, upper, size);
    }
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_aux(array, 0, size - 1, size);
}
