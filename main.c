#include "monty.h"

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
	char *opcode = NULL;

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

	while (getline(&line, &length, file) != EOF)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
			line_number++;
		else
			exec_instructions(&stack, opcode, line_number);
	}

	fclose(file);
	if (opcode != NULL)
		free(opcode);
	free_stack(stack);

	return (0);
}
