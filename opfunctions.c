#include "monty.h"
/**
 * push - adds node to the stack
 * @stack: pointer tothe pointer to the  stack head
 * @line_number: line number of the push instruction
 * Return: no return
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		newstack = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		newstack = add_dnodeint_end(stack, num);
	if (!newstack)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all elements in stack
 * @stack: double pointer to the head of the stack
 * @line_number: number of the line in the file
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		print_dlistint(*stack);
}
