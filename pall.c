#include "monty.h"

/**
 * pall - prints all values on the stack
 * @head: first element of stack
 * @lnumber: line number
 * opcode: pall
 */

void pall(stack_t **head, unsigned int lnumber)
{
	stack_t *h;
	(void) lnumber;

	if (!head)
		return;
	h = *head;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
