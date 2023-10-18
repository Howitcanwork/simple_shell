#include "shell.h"

/**
 * get_line - Read inpt from stream
 * @n: size
 * @stream_r: stream to read from
 * @line: buffer that stores the input
 * Return: number of bytes
 */
ssize_t get_line(char **line, size_t *n, FILE *stream_r)
{
	static ssize_t getin;
	char y = 'z';
	char *buf;
	int i;
	ssize_t val;

	buf = malloc(sizeof(char) * BUFSIZ);
	if (buf == 0)
		return (-1);
	if (getin == 0)
		fflush(stream_r);
	else
		return (-1);
	getin = 0;

	while (y != '\n')
	{
		i = read(STDIN_FILENO, &y, 1);
		if (i == -1 || (i == 0 && getin == 0))
		{
			free(buf);
			return (-1);
		}
		if (i == 0 && getin != 0)
		{
			getin++;
			break;
		}
		if (getin >= BUFSIZ)
			buf = _realloc(buf, getin, getin + 1);

		buf[getin] = y;
		getin++;
	}
	buf[getin] = '\0';
	g_line(line, n, buf, getin);
	val = getin;
	if (i != 0)
		getin = 0;
	return (val);
}

/**
 * g_line - assigns the line var
 * @buf:string
 * @n: size of line
 * @k: size of buffer
 * @line: Buffer that store the input str
 * Return: nothing
 */
void g_line(char **line, size_t *n, char *buf, size_t k)
{
	if (*line == NULL)
	{
		if  (k > BUFSIZ)
			*n = k;
		else
			*n = BUFSIZ;
		*line = buf;
	}
	else if (*n < k)
	{
		if (k > BUFSIZ)
			*n = k;
		else
			*n = BUFSIZ;
		*line = buf;
	}
	else
	{
		_strcpy(*line, buf);
		free(buf);
	}
}
