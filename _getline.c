#include "monty.h"

/**
 * _getline - reads a line from a stream
 * @lineptr: pointer to output buffer
 * @n: pointer to size of buffer
 * @stream: stream from which to read
 *
 * Return: number of characters read, or -1 on error
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buff_size = 256, chars_read = 0;
	int curr;
	char *temp;

	if (!(lineptr || n || stream))
		return (-1);
	*lineptr = malloc(sizeof(char) * buff_size);
	while ((curr = fgetc(stream)) != EOF)
	{
		if (chars_read + 1 >= buff_size)
		{
			buff_size += 256;
			temp = realloc(*lineptr, buff_size);
			if (!temp)
				return (-1);
			*lineptr = temp;
			*n = buff_size;
		}
		(*lineptr)[chars_read] = curr;
		chars_read++;
		if (curr == '\n')
			break;
	}
	if (chars_read == 0)
		return (-1);
	(*lineptr)[chars_read] = '\0';
	return (chars_read);
}
