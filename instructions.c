#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: address of pointer to head node
 * @line_number: line number of instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	int i, val;

	if (!new)
	{
		free(data.line);
		free_stack(stack);
		fclose(data.fp);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!data.arg)
	{
		free(new);
		free(data.line);
		free_stack(stack);
		fclose(data.fp);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; data.arg[i]; i++)
	{
		if (data.arg[i] == '+' || data.arg[i] == '-')
			continue;
		else if (!isdigit(data.arg[i]))
		{
			free(new);
			free(data.line);
			free_stack(stack);
			fclose(data.fp);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	val = atoi(data.arg);
	new->n = val;
	new->next = (*stack) ? *stack : NULL;
	*stack = new;
}

/**
 * print_all - prints all the values on a stack
 * @stack: address of pointer to top element
 * @line_number: instruction line number
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
