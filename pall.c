#include "monty.h"

/**
 * pall - Prints all the numbers of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
