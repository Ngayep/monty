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
/**
* swap - swaps the value of the top two elements to the stack
* @stack: pointer that point to stack
* @lnumber: line number of instruction
* Return: void, exit with -1 on failure
**/
void swap(stack_t **stack, unsigned int lnumber)
{
	int temp;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lnumber);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}


/**
 * free_stack - frees a stack
 * @stack: stack to be freed
 */
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

/**
* len - length of stack
* @stack: pointer that point to stack
* Return: unsigned int
**/
unsigned int len(stack_t **stack)
{
	stack_t *current;
	unsigned int lenght = 0;

	current = *stack;
	while (current)
	{
		current = current->next;
		lenght++;
	}
	return (1);
}
