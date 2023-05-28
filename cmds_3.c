#include "monty.h"

/**
 * mod - computes the remainder of the divison of the second element of a stack
 * by the top element
 * @stack: address of pointer to the top element
 * @line_number: instruction line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *sec;

	if (!*stack || stack_len(*stack) < 2)
	{
		free_stack(stack);
		free(data.line);
		fclose(data.fp);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(stack);
		free(data.line);
		fclose(data.fp);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	sec = (*stack)->next;
	sec->n %= (*stack)->n;
	pop(stack, line_number);
}
