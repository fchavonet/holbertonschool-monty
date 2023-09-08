#include "monty.h"

/**
 * exec_instructions - Executes Monty bytecode instructions.
 *
 * @stack: a pointer to the top of the stack.
 * @opcode: a pointer to a string with the instruction to execute.
 * @line_number: the line number being executed.
 *
 * Return: 0 if success.
 */
int exec_instructions(stack_t **stack, char *opcode, unsigned int line_number)
{
	int index = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"pchar", pchar},
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
