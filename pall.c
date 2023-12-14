#include "monty.h"

/**
 * pall - prints all values on the stack
 * @head: double pointer to first element of stack
 * @lnumber: line number
 * opcode: pall
 */

void pall(stack_t **head, unsigned int lnumber)
{
	stack_t *current = *head;
	(void) lnumber;

	if (head == NULL || *head == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print the int at the top of stack
 *
 * @stack: double pointer th the head
 * @lnumber: number of lines
 * Return: void
*/

void pint(stack_t **stack, unsigned int lnumber)
{
	(void) lnumber;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnumber);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the last inserted element
 *
 * @lnumber: number of lines in stack
 * @stack: pointer to the pointer to the head
 * Return: void
 */

void pop(stack_t **stack, unsigned int lnumber)
{
	stack_t *last;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", lnumber);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", lnumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		last = *stack;
		*stack = (*stack)->next;
		free(last);
	}
}

/**
 * nop - does nothing
 * @stack: pointer to pointer to the stack
 * @lnumber: number of lines in the stack
 * Return: void
 */

void nop(stack_t **stack, unsigned int lnumber)
{
	(void) stack;
	(void) lnumber;
}
