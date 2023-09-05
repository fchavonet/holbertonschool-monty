#include "monty.h"

/**
 * is_value_int - test
 *
 * @line_number: test
 *
 * Return: 0
 */
int is_value_int(unsigned int line_number)
{
	char *string = NULL;

	string = strtok(NULL, " \t\n");

	int value = 0;
	int index = 0;

	if (string == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (string[index] != '\0')
	{
		if (*string < '0' || *string > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(string);
			exit(EXIT_FAILURE);
		}
		index++;
	}

	value = atoi(string);

	return (value);
}

/**
 * push - Pushes an element onto the stack.
 *
 * @head: pointer to the head of the stack.
 * @line_number: test
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int value = is_value_int(line_number);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
