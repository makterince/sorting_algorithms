#include "sort.h"
#include <stdio.h>

/**
 *swap - Swap two integer values.
 *@a: Pointer to the first integer.
 *@b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *partition - Lomuto partition scheme.
 *@array: Array to be partitioned.
 *@size: Size of the array.
 *@low: Starting index of the partition to be sorted.
 *@high: Ending index of the partition to be sorted.
 *Return: The index of the pivot element.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
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
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 *quicksort - Implementation of the quicksort algorithm.
 *@array: Array to be sorted.
 *@size: Size of the array.
 *@low: Starting index of the partition to be sorted.
 *@high: Ending index of the partition to be sorted.
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quicksort(array, size, low, pivot - 1);
		quicksort(array, size, pivot + 1, high);
	}
}
/**
 *quick_sort - Sorts an array of integers in ascending order using the Quick
 *sort algorithm.
 *@array: Array to be sorted.
 *@size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quicksort(array, size, 0, size - 1);
}
