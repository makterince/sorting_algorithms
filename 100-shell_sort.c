#include "sort.h"
/**
 *shell_sort - sorts an array of integers in ascending order
 *using the Shell sort algorithm with the Knuth sequence
 *@array: array of integers to sort
 *@size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int tmp;
	
	/* Calculate gap using the Knuth sequence */
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		/* Perform insertion sort on subarrays defined by gap */
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		/* Decrease gap */
		gap = (gap - 1) / 3;
		/* Print array after each decrease in gap */
		print_array(array, size);
	}
}
