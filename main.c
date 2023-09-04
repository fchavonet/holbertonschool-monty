#include "monty.h"

void free_all(char *line, stack_t *stack)
{
	free(line);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t length = 0;
	unsigned int line_number = 0;
	char *opcode = NULL;
	char *number = NULL;
	int value = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &length, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			number = strtok(NULL, " \t\n");
			if (number == NULL)
			{
				fprintf(stderr, "L%u usage: push integer\n", line_number);
				fclose(file);
				free_all(line, stack);
				exit(EXIT_FAILURE);
			}
			value = atoi(number);
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else
		{
			fprintf(stderr, "L%u usage: unknow instruction %s\n", line_number, opcode);
			fclose(file);
			free_all(line, stack);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free_all(line, stack);
	return (EXIT_SUCCESS);
}
