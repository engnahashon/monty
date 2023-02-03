#include "monty.h"
#include "monty.h"

opret_q ret_and_q = {0, 0};

int check_codes(char *command, stack_t **stack, size_t line_num)
{
	instruction_t opcodes[] = {
		{"rotr", rotr},
		{"rotl", rotl},
		{"pstr", pstr},
		{"pchar", pchar},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{NULL, NULL}
	};
	size_t i = 0;

	while (opcodes[i].opcode)
	{
	if (strcmp(command, opcodes[i].opcode) == 0)
	{
		opcodes[i].f(stack, line_num);
		return ret_and_q.opcode_return;
	}
	i++;
	}
	printf("L%lu: unknown instruction %s\n", line_num, command);
	ret_and_q.opcode_return = 1;
	return 1;
}
