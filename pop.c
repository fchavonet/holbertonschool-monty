#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;

	current_node = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current_node = current_node->next;
	free(*stack);
	*stack = current_node;
}
