#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *temp;
    listint_t *look_ahead;
    listint_t *new_node;

    new_node = malloc(sizeof(listint_t));
    new_node->n = number;
    new_node->next = NULL;

    if (head == NULL || *head == NULL || (*head)->n >= new_node->n) {
        new_node->next = *head;
        *head = new_node;
        return *head;
    }

    temp = *head;
    look_ahead = (*head)->next;

    while (look_ahead != NULL && look_ahead->n < number) {
        temp = temp->next;
        look_ahead = look_ahead->next;
    }

    temp->next = new_node;
    new_node->next = look_ahead;

    return *head;
}
