#include "main.h"
static char buffer[1024];
static int buf_index;

/**
 * flush_buffer - write contents of the internal buffer to stdout
 * Return: current internal buffer index (0 after flush)
 */
int flush_buffer(void)
{
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		buf_index = 0;
	}
	return (buf_index);
}

/**
 * buffered_write - append a character to the internal buffer
 * @c: character to write
 * Return: new internal buffer index
 */
int buffered_write(char c)
{
	if (buf_index == 1024)
	{
		flush_buffer();
	}
	buffer[buf_index++] = c;
	return (buf_index);
}
