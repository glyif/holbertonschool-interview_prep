#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks if there is a cycle in a linked list
 * @list: pointer to a node in a list
 * Return: 0 for no cycle, 1 for cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow_track = list;
	listint_t *fast_track = list->next;

	if (list == NULL)
	{
		return (0);
	}

	while (slow_track != fast_track)
	{
		if (fast_track == NULL || fast_track->next == NULL)
		{
			return (0);
		}
		slow_track = slow_track->next;
		fast_track = fast_track->next->next;
	}
	return (1);
}
