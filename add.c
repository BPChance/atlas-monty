#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* store pointers to the top two nodes */
	top = *stack;
	second = (*stack)->next;

	/* add values of top two nodes */
	second->n += top->n;

	/* remove top node */
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	/* free memory of removed node */
	free(top);
}
