#include <stdlib.h>
#include <stdio.h>

#include "search.h"

/**
 * linear_skip - linear search using skip list
 * @list: head of skip list
 * @value: value to search for
 * Return: node with value or null
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *slow;
	skiplist_t *fast;

	slow = list;
	fast = slow->express;

	if (list == NULL)
		return (NULL);

	while (fast)
	{
		printf("Value checked at index [%d] = [%d]\n", (int) fast->index, fast->n);

		if (value <= fast->n && value >= slow->n)
		{
			printf("Value found between indexes [%d] and [%d]\n",
				   (int) slow->index, (int) fast->index);

			while (slow->index <= fast->index)
			{
				printf("Value checked at index [%d] = [%d]\n", (int) slow->index, slow->n);
				if (slow->n == value)
					return (slow);
				slow = slow->next;
			}
		}

		slow = slow->next;
		fast = fast->express;
	}

	return (NULL);
}
