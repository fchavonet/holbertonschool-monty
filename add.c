#include "monty.h"

/**
 * add -  Adds the top two elements of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current_node = (*stack)->next;
	current_node->n += (*stack)->n;
	pop(stack, line_number);
}
