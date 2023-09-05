#include "monty.h"

/**
 * free_all - Frees memory allocated for the stack and a line.
 *
 * @stack: a pointer to the top of the stack.
 * @line: a line of Monty bytecode.
 */
void free_all(stack_t *stack, char *line)
{
	stack_t *temp_stack = NULL;

	free(line);

	while (stack != NULL)
	{
		temp_stack = stack;

		stack = stack->next;
		free(temp_stack);
	}
}

/**
 * execute_instruction - Executes Monty bytecode instructions.
 *
 * @stack: a pointer to the top of the stack.
 * @line: a line of Monty bytecode.
 * @line_number: the line number being executed.
 *
 * Return: 0 if success.
 */
int execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	int index = 0;
	char *opcode = strtok(line, " \t\n");

	if (opcode == NULL)
		exit(EXIT_FAILURE);

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (instructions[index].opcode != NULL)
	{
		if (strcmp(opcode, instructions[index].opcode) == 0)
		{
			instructions[index].f(stack, line_number);

			return (0);
		}
		index++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * main - Entry point of the programm.
 *
 * @argc: the number of command-line arguments.
 * @argv: an array of command-line argument strings.
 *
 * Return: 0 if success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t length = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &length, file) != -1)
	{
		line_number++;
		execute_instruction(&stack, line, line_number);
	}

	fclose(file);
	free_all(stack, line);

	return (0);
}
