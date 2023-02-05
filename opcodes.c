#include "monty.h"
/**
 * pall - Print all values in the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	(void) line_num;
	walker = *stack;
	while (walker != NULL)
	{
		printf("%d\n", walker->n);
		walker = walker->next;
	}
}
/**
  * pint - Print top element of the stack
  * @stack: Double pointer to the top of the stack
  * @line_num: line of the file the command was found
  */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (ret_and_q.opcode_return != 1)
		printf("%d\n", (*stack)->n);

}
/**
  * pop - removes top element of stack
  * @stack: pointer to top element of stack
  * @line_num: line number
  */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *walker;

	walker = *stack;
	if (walker == NULL)
	{
		printf("L%u: can't pop an stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (ret_and_q.opcode_return != 1)
	{
		temp = walker;
		*stack = walker->next;
		if (walker != NULL)
			walker->prev = NULL;
		free(temp);
	}
}
/**
  * swap - swaps the top two elements of the stack
  * @stack: double pointer to top of stack
  * @line_num: line number
  */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;
	int temp;

	walker = *stack;
	if (walker == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (ret_and_q.opcode_return != 1)
	{
		temp = walker->n;
		walker->n = walker->next->n;
		walker->next->n = temp;
	}
}
