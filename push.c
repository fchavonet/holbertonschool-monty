#include "monty.h"

/**
 * is_int - check if string received is int or not
 *
 * @opcode: string to check
 *
 * Return: -1 if sring is not int or 1 if yes
 */
int is_int(char *opcode)
{
	int i;

	if (opcode == NULL)
		return (-1);

	for (i = 0; opcode[i] != '\0'; i++)
	{
		if (opcode[i] != '-' && isdigit(opcode[i]) == 0)
			return (-1);
	}
	return (1);
}

/**
 * push - Pushes an element onto the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *number_string = NULL;
	int number = 0;

	number_string = strtok(NULL, " \t\n");

	if (number_string == NULL || is_int(number_string) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(number_string);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
