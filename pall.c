#include "monty.h"

/**
 * pall - prints all values on the stack
 * @stack: stack to be printed
 */

void pall(const stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
