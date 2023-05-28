#include "monty.h"

/**
 * split_line - breaks instruction line into string tokens
 * and puts them in the structure
 *
 * Return: 1 on success or 0 if line is blank
 */
int split_line(void)
{
	char *delim = " \n\t\r\a\v";
	int i, all_spaces = 1;

	if (strcmp(data.line, "\n") == 0)
		return (0);
	for (i = 0; data.line[i] != '\n' && data.line[i] != '#'; i++)
	{
		if (data.line[i] != ' ')
		{
			all_spaces = 0;
			break;
		}
	}
	if (all_spaces)
		return (0);
	data.cmd = strtok(data.line, delim);
	if (data.cmd[0] == '#')
		return (0);
	data.arg = strtok(NULL, delim);
	return (1);
}
