#include "monty.h"

/**
 * mod - computes the rest of the division
 *       of the second top element of the
 *       stack by the top element of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current_node = (*stack)->next;
	if (current_node->n == 0 || current_node->prev->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	current_node->n = current_node->n % (*stack)->n;
	pop(stack, line_number);
}
