#include "monty.h"

/**
 * gettonumber - get the first number in a string
 * @s:
 * the string should contain only spaces and a valid opcode before
 * Return: a pointer to where the number (and a number is not 4e) is or NULL
 */
char gettonumber(char *s)
{
	char *c;
	int res, i, neg = 1;

	res = i = 0;
	if (!s)
		return (0);

	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			neg = -1;
		i++;
		++s;
	}

	if (*s == '\0')
		return (0);
	c = s;
	while (*c && *c >= '0' && *c <= '9')
		c++;

	if (!(*c == '\0' || *c == '\n' || *c == ' ' || *c == '\t'))
	return (0);

	res = atoi(s) * neg;
	if (res < 0)
	{
		s[i - 1] = '-';
		return ((*s) - 1);
	}
	return (*s);
}

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
		/**{"swap", swap},
		*{"add", add},
		*{"nop", nop},
		*{"sub", sub},
		*{"div", div},
		*{"mul", mul},
		*{"mod", mod},
		*{"pchar", pchar},
		*{"pstr", pstr},
		*{"rotl", rotl},
		*{"rotr", rotr},
		*{"stack", stack},
		*{"queue", queue},
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
