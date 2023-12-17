#include "monty.h"

/**
 * get_func - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t funct_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"stack", stack_handle},
		{"queue", queue},
		{"nop", nop},
		{"pchar", pchar},
		/**
		*{"swap", swap},
		*{"add", add},
		*{"sub", sub},
		*{"div", div},
		*{"mul", mul},
		*{"mod", mod},
		*{"pstr", pstr},
		*{"rotl", rotl},
		*{"rotr", rotr},
		*/
		{NULL, NULL}
	};

	int code = 17, i;

	for (i = 0; i < code; i++)
	{
		if (strcmp(funct_arr[i].opcode, parsed[0]) == 0)
		{
			return (funct_arr[i].f);
		}
	}
	return (NULL);
}

/**
 * free_all - memory freeing function
 * @allz: indicates what to free
 */
void free_all(int allz)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_everything(data.words);
		data.words = NULL;
	}

	if (allz)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}
