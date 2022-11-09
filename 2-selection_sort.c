#include "sort.h"
/**
  * selection_sort - Sort an array of integers in ascending order
  *                  using the selection sort algorithm.
  * @array: array to sort
  * @size: size of array
  * Description: Prints the array after each swap.
  *
  * Author: Dennis Appiah
  */
void selection_sort(int *array, size_t size)
{
	size_t i, i2;
	int min, tmp, idx;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (i2 = i + 1; i2 < size; i2++)
		{
			if (min > array[i2])
			{
				min = array[i2];
				idx = i2;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
