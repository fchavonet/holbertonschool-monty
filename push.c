#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 *
 * @head: pointer to the head of the stack.
 * @number: the integer number to push onto the stack.
 */
void push(stack_t **head, int number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;


	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
