#ifndef	SORT_H
#define	SORT_H

#include <stdlib.h>

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void sift_down(int *array, size_t size, size_t start, size_t end);
void swap(int *array, size_t size, size_t i, size_t j);

void print_array(const int *array, size_t size);

#endif

