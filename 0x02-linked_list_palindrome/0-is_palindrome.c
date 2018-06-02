#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: head of linked list
 * Return: void
 */
void reverse_list(listint_t **head)
{
	listint_t *current;
	listint_t *next;
	listint_t *prev;

	current = *head;
	next = NULL;
	prev = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}


/**
 * compare_lists - compares 2 lists
 * @first_head: head of first list
 * @second_head: head of second list
 * Return: 0 if not same, 1 if same
 */
int compare_lists(listint_t *first_head, listint_t *second_head)
{
	listint_t *first_temp;
	listint_t *second_temp;

	first_temp = first_head;
	second_temp = second_head;

	if (first_head == NULL && second_head != NULL)
		return (0);

	while (first_temp && second_head)
	{
		if (first_temp->n == second_temp->n)
		{
			first_temp = first_temp->next;
			second_temp = second_temp->next;
		} else
		{
			return (0);
		}
	}

	if (first_temp == NULL && second_temp == NULL)
		return (1);

	return (0);

}
/**
 * is_palindrome - check if linked list is a palindrome
 * @head: head of linked list
 * Return: 1 for palindrome, 0 for not
 */
int is_palindrome(listint_t **head)
{
	listint_t *mid;
	listint_t *last;
	listint_t *fast;
	listint_t *slow;
	listint_t *slow_temp;

	mid = last = fast = slow = *head;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow_temp = slow;
		slow = slow->next;
	}

	/**
	 * this is for odd cases,
	 * there will be a node left out that
	 * doesn't need to be compared
	 */
	if (fast)
	{
		mid = slow;
		slow = slow->next;
	}

	slow_temp->next = NULL;
	reverse_list(&slow);
	return (compare_lists(*head, slow));
}
