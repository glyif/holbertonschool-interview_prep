#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - sorted array to balanced avl
 * @array: array to covert to avl
 * @size: size of array
 * Return: root of avl
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl;

	if (array == NULL || size <= 0)
		return (NULL);

	avl = array_to_avl_helper(array, 0, size - 1, NULL);

	return (avl);
}

/**
 * array_to_avl_helper - helper for creating avl from sorted array
 * @array: array
 * @start: starting index
 * @finish: ending index
 * @parent: parent node to set as parent
 * Return: newly created node
 */
avl_t *array_to_avl_helper(int *array, int start, int finish, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > finish)
		return (NULL);

	mid = (start + finish) / 2;
	root = create_new_node(array[mid], parent);

	root->left = array_to_avl_helper(array, start, mid - 1, root);
	root->right = array_to_avl_helper(array, mid + 1, finish, root);

	return (root);
}

/**
 * create_new_node - creates new node with data
 * @data: int data of new node
 * @parent: parent node of new node
 * Return: new node with set data and parent
 */
avl_t *create_new_node(int data, avl_t *parent)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	new_node->n = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
