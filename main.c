#include "monty.h"

line_t data = {0, NULL, NULL, NULL};
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
	int split, exec;
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
	while (_getline(&line, &len, fp) > 0)
	{
		data.line = line;
		data.num += 1;
		split = split_line();
		if (split == 0)
		{
			free(line);
			continue;
		}
		exec = execute_instruction(&stack);
		if (exec == -1)
		{
			free(line);
			fclose(fp);
			fprintf(stderr, "L%d: unknown instruction %s\n",
					data.num, data.cmd);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	free(line);
	free_stack(&stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
