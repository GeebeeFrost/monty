#include "monty.h"

/**
 * execute_instruction - executes instruction selected
 * @stack: address of pointer to top of stack
 *
 * Return: 1 on success, -1 on failure
 */
int execute_instruction(stack_t **stack)
{
	void (*f)(stack_t **, unsigned int);

	f = _select(data.cmd);
	if (!f)
		return (-1);
	f(stack, data.num);
	return (1);
}

/**
 * _select - selects instruction to execute based on opcode
 * @op: entered opcode
 *
 * Return: pointer to the function or NULL if not found
 */
void (*_select(char *op))(stack_t **, unsigned int)
{
	unsigned int i;
	instruction_t options[] = {
		{"push", push},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	for (i = 0; options[i].opcode; i++)
	{
		if (strcmp(options[i].opcode, op) == 0)
			return (options[i].f);
	}
	return (NULL);
}
