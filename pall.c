#include "monty.h"

/**
 * pall - prints all values on the stack
 * @head: first element of stack
 * @lnumber: line number
 * opcode: pall
 */

void pall(stack_t **head, unsigned int lnumber)
{
	(void) lnumber;

	if (!head)
		return;

	while (*head != NULL)
	{
		printf("%d\n", *head->n);
		*head = *head->next;
	}
}
