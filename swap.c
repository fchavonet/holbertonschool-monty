#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	stack_t *current_node = NULL;

	current_node = *stack;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = number;
}
