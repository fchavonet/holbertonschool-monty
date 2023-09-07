#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	if (current_node != NULL)
		printf("%d\n", current_node->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
