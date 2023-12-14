#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @number: stackline number
 * Return: no return
 */

void push(stack_t **stack, unsigned int number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

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
