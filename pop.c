#include "monty.h"
/**
 * pop - remove the top element of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	/* store top node in temp variable */
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* move stack pointer to next node */
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	/* free memory of removed node */
	free(temp);
}
