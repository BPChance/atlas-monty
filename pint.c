#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d:can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* prints value at the top of the stack */
	printf("%d\n", (*stack)->n);
}
