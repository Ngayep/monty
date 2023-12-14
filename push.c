#include "monty.h"
/**
 * push - add node to the stack
 * @head: pointer to  stack head
 * @line: pointer to line
 * @lnumber: stackline number
 * Return: no return
 */

void push(stack_t **head, char *line, unsigned int lnumber)
{
	stack_t *newstack = NULL;
	unsigned int i;

	newstack = malloc(sizeof(stack_t));
	if (newstack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", lnumber);
		exit(EXIT_FAILURE);
	}

	if (line == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", lnumber);
		exit(EXIT_FAILURE);
	}
	for (i = 0; line[i]; i++)
	{
		if (line[0] == '-' && i == 0)
			continue;
		if (line[i] < 48 || line[i] > 57)
		{
			fprintf(stderr, "L%u: usage: push integer\n", lnumber);
			exit(EXIT_FAILURE);
		}
	}
	newstack->n = atoi(line);
	newstack->prev = NULL;
	newstack->next = NULL;

	if (*head != NULL)
	{
		newstack->next = *head;
		(*head)->prev = newstack;
	}
	*head = newstack;
}

void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
