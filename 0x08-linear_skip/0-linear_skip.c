#include <stdlib.h>
#include <stdio.h>

#include "search.h"

/**
 * linear_search - linear search through linked list
 * @first: first node
 * @last: last node
 * @value: value to search for
 * Return: found node or null;
 */
skiplist_t *linear_search(skiplist_t *first, skiplist_t *last, int value)
{
	while (first && first->index <= last->index)
	{
		printf("Value checked at index [%d] = [%d]\n", (int) first->index, first->n);
		if (first->n == value)
			return first;
		first = first->next;
	}
	return NULL;
}

/**
 * linear_skip - linear search using skip list
 * @list: head of skip list
 * @value: value to search for
 * Return: node with value or null
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *slow;
	skiplist_t *temp;
	skiplist_t *fast;
	int last_index;
	int count;

	temp = list;
	slow = temp->express;
	fast = temp->express;
	count = 0;
	last_index = 0;

	if (list == NULL)
		return (NULL);

	while (fast)
	{
		printf("Value checked at index [%d] = [%d]\n", (int) fast->index, fast->n);

		if ((value <= fast->n && value >= slow->n) || (count == 0 && value <= fast->n))
		{
			if (count == 0) {
				slow = temp;
			}

			printf("Value found between indexes [%d] and [%d]\n",
				   (int) slow->index, (int) fast->index);

			return linear_search(slow, fast, value);
		}

		count++;

		slow = fast;
		fast = fast->express;
	}

	temp = slow;
	last_index = slow->index;

	while(temp->next)
	{
		last_index++;
		temp = temp->next;
	}

	printf("Value found between indexes [%d] and [%d]\n",
		   (int) slow->index, (int) temp->index);

	return (linear_search(slow, temp, value));
}
