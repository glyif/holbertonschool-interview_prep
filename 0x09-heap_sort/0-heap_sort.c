#include "sort.h"

/**
 *	heap_sort - heap sort function
 *
 *	@array: Array to be sorted
 *	@size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, end, 0);
		end--;
		sift_down(array, size, 0, end);
	}
}

/**
 *	heapify - convert the array to a heap structure
 *
 *	@array: Array to be heapified
 *	@size: Number of elements in @array
 */
void heapify(int *array, size_t size)
{
	/* calculate parent of last position */
	long start = ((size - 1) - 1) / 2;

	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}

/**
 *	sift_down - sift the start element to its appropriate position in the heap
 *
 *	@array: Array to use for the sift
 *	@size: Number of elements in @array
 *	@start: Starting position to use for the sift
 *	@end: End position to use for the sift
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root;
	size_t child;
	size_t swp;

	root = start;
	/* while left child position is valid */
	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1; /* position of left child */
		swp = root;
		if (array[swp] < array[child])
			swp = child;
		if (child + 1 <= end && array[swp] < array[child + 1])
			swp = child + 1;
		if (swp != root)
		{
			swap(array, size, root, swp);
			root = swp;
		}
		else
			break;
	}
}

/**
 *	swap - swaps the values at positions i and j in the array
 *
 *	@array: Array to use for the swap
 *	@size: Number of elements in @array
 *	@i: first position to swap
 *	@j: second position to swap
 *
 */
void swap(int *array, size_t size, size_t i, size_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size); /* print the array after every swap */
}

