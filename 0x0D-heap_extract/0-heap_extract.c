#include "binary_trees.h"

/**
 * heap_size - calculates the size of the heap
 *
 * @heap: start heap node to calculate the size
 *
 * Return: size of the heap
 */
int heap_size(heap_t *heap)
{
	int size = 0;

	if (heap)
	{
		size += heap_size(heap->left);
		size += heap_size(heap->right);
		size++;
	}
	return (size);
}

/**
 * my_log2 - calculates the log2 of the given value
 *
 * @n: value to use for the log2 calculation
 *
 * Return: log2 of the value
 */
int my_log2(int n)
{
	int count = 0;

	while (n != 1)
	{
		n >>= 1;
		count++;
	}
	return (count);
}

/**
 * heapify - rebuilds the heap structure
 *
 * @heap: pointer to the heap node to start from
 */
void heapify(heap_t *heap)
{
	heap_t *biggest;
	int tmp;

	if (heap == NULL)
		return;
	/* if the left node is the biggest */
	if (heap->left && heap->left->n > heap->n)
		biggest = heap->left;
	else
		biggest = heap;

	/* if the right node is the biggest */
	if (heap->right && heap->right->n > biggest->n)
		biggest = heap->right;

	if (biggest != heap)   /* if one of the children is the biggest, heapify */
	{
		tmp = heap->n;
		heap->n = biggest->n;
		biggest->n = tmp;
		heapify(biggest);
	}
}

/**
 * heap_extract - extracts the value at the root node and removes the node
 *
 * @root: double pointer to the heap root node
 *
 * Return: value stored on the root node or 0 if failure
 */
int heap_extract(heap_t **root)
{
	heap_t **delete_pos;
	int last_pos, mask, value;

	last_pos = heap_size(*root);

	if (last_pos == 0)
		value = 0;
	else if (last_pos == 1)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
	}
	else
	{
		value = (*root)->n;
		mask = 1 << (my_log2(last_pos) - 1);
		delete_pos = root;
		while (mask)
		{
			if (mask & last_pos)
				delete_pos = &((*delete_pos)->right);
			else
				delete_pos = &((*delete_pos)->left);
			mask >>= 1;
		}
		(*root)->n = (*delete_pos)->n;
		free(*delete_pos);
		*delete_pos = NULL;
		heapify(*root);
	}
	return (value);
}
