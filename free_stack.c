#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: address of pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
