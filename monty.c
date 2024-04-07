#include "monty.h"

#define STACK_SIZE 1000
#define EXIT_FAILURE 1
/** define global variable stack */
stack_t *stack = NULL;

/**
 * push - pushes an integer onto the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all elements in the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - frees memory allocated for the stack nodes
 * @stack: pointer to top of stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * main - entry point
 * @argc: number of args
 * @argv: array of strings where each element is a command
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char line[100], *opcode, *arg_str;
	int arg, line_number = 0, i;

	if (argc != 2)
	{
		if (strncmp(argv[0], "./", 2) == 0)
			fprintf(stderr, "USAGE: %s file\n", argv[0] + 2);
		else
			fprintf(stderr, "USAGE: %s file\n", argv[0]);

		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	instruction_t instructions[] =
	{
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \n");

		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg_str = strtok(NULL, " \n");

			if (arg_str == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			arg = atoi(arg_str);

			push(&stack, arg);
		}
		else
		{
			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number);
					break;
				}
			}
			if (instructions[i].opcode == NULL)
			{
				printf("L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
