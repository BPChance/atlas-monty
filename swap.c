#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: line_number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	/* store pointers to the top two nodes */
	stack_t *top;
	stack_t *second;
	int temp;
	/* check if stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* store pointers to the top two nodes */
	top = *stack;
	second = (*stack)->next;
	/* swap values of top two nodes */
	temp = top->n;
	top->n = second->n;
	second->n = temp;
}
