#include "monty.h"
/**
 * find_command - Parse the line to find the given opcode
 * @line: Line grabbed from monty file
 * @stack: Double pointer pointing to top of stack/queue
 * @line_num: Line number in the file the line was on
 * Return: The name of the command found
 **/
char *find_command(char *line, stack_t **stack, unsigned int line_num)
{
	char *command, *push_arg;

	command = strtok(line, "\n\t\r ");
	if (!command || command[0] == '#')
		return "nop";

	if (!strcmp(command, "push"))
	{
		push_arg = strtok(NULL, "\n \t\r");
		if (!push_arg || int_check(push_arg))
		{
			printf("L%u: usage: push integer\n", line_num);
			ret_and_q.opcode_return = 1;
			return "nop";
		}

		if (ret_and_q.queue_val == 0)
			add_node(stack, atoi(push_arg));
		else
			add_node_end(stack, atoi(push_arg));

		return "nop";
	}

	if (!strcmp(command, "stack"))
	{
		ret_and_q.queue_val = 0;
		return "nop";
	}

	if (!strcmp(command, "queue"))
	{
		ret_and_q.queue_val = 1;
		return "nop";
	}

	return command;
}

/**
 * int_check - Check if the given argument to push is a valid integer or not
 * @push_arg: The string argument found after the push opcode
 * Return: 1 if it's not a valid integer, 0 if it is
 **/
int int_check(char *push_arg)
{
    int i;

    if (push_arg == NULL || *push_arg == '\0')
        return (1);
    if (*push_arg == '-' || isdigit(*push_arg))
    {
        for (i = 1; push_arg[i]; i++)
            if (!isdigit(push_arg[i]))
                return (1);
    }
    else
        return (1);
    return (0);
}
