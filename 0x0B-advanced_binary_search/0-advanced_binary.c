#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - prints array
 * @array: array to print
 * @start: start index
 * @stop: end index
 */
void print_array(int *array, int start, int stop)
{
	int i;

	for (i = start; i < stop - 1; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}

/**
 * binary_search - binary search helper function
 * @array: array to search
 * @start: start searching index
 * @stop: stop searching index
 * @value: value to find
 * Return: index of found value or -1
 */
int binary_search(int *array, int start, int stop, int value)
{
	printf("Searching in array: ");
	print_array(array, start, stop);

	if (stop - 1 == start && array[start] != value)
		return (-1);

	if (stop >= start)
	{
		int mid = start + (stop - start) / 2;

		if (array[start] == value)
			return (start);

		if (array[mid] > value)
			return (binary_search(array, start, mid, value));


		return (binary_search(array, mid, stop, value));
	}


	return (-1);
}

/**
 * advanced_binary - binary search that returns index
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: index of found value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
	{
		return (-1);
	}

	return (binary_search(array, 0, (int) size, value));
}
