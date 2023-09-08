#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current_node = *stack;
	char character = '0';

	character = current_node->n;

	while (current_node != NULL)
	{
		printf("%c\n", character);
		current_node = current_node->next;
	}
}
