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

	if (!head)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
