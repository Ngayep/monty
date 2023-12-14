#include "monty.h"
/**
 * _push - add node to the stack
 * @head: stack head
 * @number: stackline number
 * Return: no return
 */

void _push(stack_t **head, unsigned int number)
{
	if (!newNode)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	newNode->n = number;
	newNode->prev = NULL;

	if (*stack != NULL)
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	else
	{
		newNode->next = NULL;
	}

	*stack = newNode;
}
