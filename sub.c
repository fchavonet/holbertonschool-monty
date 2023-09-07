#include "monty.h"

/**
 * sub - Subtracts the top element of the stack
 *       from the second top element of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current_node = (*stack)->next;
	current_node->n = current_node->n - (*stack)->n;
	pop(stack, line_number);
}
