#include "monty.h"
/**
 * push - adds node to the stack
 * @stack: pointer tothe pointer to the  stack head
 * @line_number: line number of the push instruction
 * Return: no return
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " ");
	long int value;
	stack_t *head = malloc(sizeof(stack_t));

	if (!argument)
	{
		fprintf(stderr, "L%u: Missing argument for 'push'\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);
	if (value == 0 && errno == EINVAL)
	{
		fprintf(stderr, "L%u: Invalid argument '%s'\n", line_number, argument);
		exit(EXIT_FAILURE);
	}

	if (!head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	head->n = value;
	head->prev = NULL;
	head->next = *stack;

	*stack = head;
}

/**
 * pall - prints all elements in stack
 * @stack: pointeer to the head of the stack
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;
	if (!stack)
		return;
	while (head)
	{
		printf("%d", head->n);
		if (head->next)
		{
			printf(" ");
		}
		head = head->next;
	}
	printf("\n");
}
