#include "monty.h"
/**
  * rotl - rotates the stack at the top
  * @stack: double pointer to top of the stack
  * @line_num: line number
  */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *walker, *node_1, *node_2;

	(void) line_num;
	if (*stack != NULL)
	{
		walker = node_1 = *stack;
		node_2 = walker->next;
		while (walker->next != NULL)
			walker = walker->next;
		walker->next = node_1;
		node_1->prev = walker;
		node_1->next = NULL;
		node_2->prev = NULL;
		*stack = node_2;
	}
}
/**
  * rotr - rotates the stack at the bottom
  * @stack: double pointer to top of the stack
  * @line_num: line number
  */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *node_last, *node_2_last;

	(void) line_num;
	if (*stack != NULL)
	{
		node_last = *stack;
		while (node_last->next != NULL)
			node_last = node_last->next;
		node_2_last = node_last->prev;
		node_2_last->next = NULL;
		node_last->next = *stack;
		(*stack)->prev = node_last;
		*stack = node_last;
	}
}
