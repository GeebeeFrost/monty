#include "monty.h"

line_t data = {0, NULL, NULL, NULL, NULL};
/**
 * main - interpreter for Monty ByteCode files
 * @ac: number of arguments
 * @av: array of argument strings
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "rb");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	data.fp = fp;
	while (_getline(&line, &len, fp) > 0)
	{
		data.line = line;
		data.num += 1;
		if (split_line() == 0)
		{
			free(line);
			continue;
		}
		if (execute_instruction(&stack) == -1)
		{
			free(line);
			fclose(fp);
			free_stack(&stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", data.num, data.cmd);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	free(line);
	free_stack(&stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
