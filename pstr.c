#include "monty.h"

/**
 * pstr - prints the string starting at
 *        the top of the stack, followed
 *        by a new line.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		if ((current_node->n < 65) || (current_node->n > 122))
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
