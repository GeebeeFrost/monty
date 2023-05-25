#include "monty.h"

/**
 * add - adds the top two elements of a stack when
 * opcode is add
 * @stack: address of pointer to the top element
 * @line_number: instruction line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *sec, *temp = *stack;

	if (!*stack || stack_len(*stack) < 2)
	{
		free_stack(stack);
		free(data.line);
		fclose(data.fp);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sec = (*stack)->next;
	sec->n += temp->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: address of pointer to the top element
 * @line_number: instruction line number
 */
void nop(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	(void)line_number;
}
