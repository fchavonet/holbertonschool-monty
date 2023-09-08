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

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	character = current_node->n;

	if ((character < 0) || (character > 126))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", character);
	current_node = current_node->next;
}
