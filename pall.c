#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 *
 * @stack: pointer to the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
