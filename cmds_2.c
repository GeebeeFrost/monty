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

/**
 * sub - subtracts the top element of a stack from the second top element
 * @stack: address of pointer to the top element
 * @line_number: instruction line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *sec, *temp = *stack;

	if (!*stack || stack_len(*stack) < 2)
	{
		free_stack(stack);
		free(data.line);
		fclose(data.fp);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sec = temp->next;
	sec->n -= temp->n;
	pop(stack, line_number);
}

/**
 * divide - divides the second element of a stack by the top element
 * @stack: address of pointer to the top element
 * @line_number: instruction line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *sec, *temp = *stack;

	if (!*stack || stack_len(*stack) < 2)
	{
		free_stack(stack);
		free(data.line);
		fclose(data.fp);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	sec = temp->next;
	sec->n /= temp->n;
	pop(stack, line_number);
}
