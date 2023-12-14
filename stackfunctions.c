#include "monty.h"

/**
 * add_node - push or enqueue an element at the beginning of the stack
 * @head: pointer to dll
 * @n: value to add
 * Return: pointer to new node or NULL
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;
	return (new);
}

/**
 * add_node_end - add node at the end of a dll
 * @head: pointer to a linked list
 * @n: value to insert
 * Return: address of node or NULL
 */

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new, *temp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		for (temp = *head; temp->next;)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
