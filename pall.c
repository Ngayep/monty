#include "monty.h"

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
 * @line_number: number of lines in stack
 * @stack: pointer to the pointer to the head of the stack
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * nop - does nothing
 * @stack: pointer to pointer to the stack
 * @line_number: number of lines in the stack
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pchar - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * pstr - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}
