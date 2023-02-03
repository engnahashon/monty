#include "monty.h"
#include <stdio.h>
/**
  * main - main entry point for the function
  * @argc: number of args
  * @argv: arguement vector
  *
  * Return: 1 if EOF, EXIT_FAILURE on exit
  */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL, *command = NULL;
    size_t size = 0, line_num = 1;
    stack_t *stack = NULL;
    ssize_t read = 0;

    if (argc != 2)
    {
        fprintf(stderr, "usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &size, file)) != -1)
    {
        command = find_command(line, &stack, line_num);
        if (strcmp(command, "nop"))
            check_codes(command, &stack, line_num);
        if (ret_and_q.opcode_return != 0)
        {
            free_and_exit(line, file, stack);
        }
        line_num++;
    }

    free_stack(stack);
    free(line);
    fclose(file);
    return (0);
}
