#include "sort.h"

/**
  * bubble_sort - sorts an array of integers in
  * ascending order using the Bubble sort algorithm
  * @array: array to sort
  * @size: size of the array
  *
  * Return: nothing
  */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; ++i)
	{
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j + 1], &array[j]);
				print_array(array, size);
			}
		}
	}
}

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
