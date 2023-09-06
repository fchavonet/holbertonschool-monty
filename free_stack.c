#include "monty.h"

/**
 * free_stack - Frees memory allocated for the stack.
 *
 * @stack: a pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current_node = NULL;

	while (stack != NULL)
	{
		current_node = stack;

		stack = stack->next;
		free(current_node);
	}
}
