#include "monty.h"
/**
 * add_node - Add a node to the top of the list
 * @stack: Double pointer to the top of the stack
 * @push_value: The value to assign to the new node
 **/
void add_node(stack_t **stack, int push_value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
		return;
	}
	new_node->next = *stack;
	new_node->prev = NULL;
	new_node->n = push_value;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
  * add_node_end - Add a node at the end of the list
  * @stack: Double pointer to the top of the stack
  * @push_value: The value to assign to the new node
 **/
void add_node_end(stack_t **stack, int push_value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *walker = *stack;

	if (!new_node)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
		return;
	}
	new_node->n = push_value;
	new_node->next = NULL;
	if (!walker)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}
	while (walker->next)
		walker = walker->next;
	walker->next = new_node;
	new_node->prev = walker;
}
