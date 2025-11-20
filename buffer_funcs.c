#include "main.h"
static char buffer[1024];

static int index;
/**
 * flush_buffer - writes the contents of the buffer to stdout
 *
 * Return: 0 on success
 */
int flush_buffer(void)
{
	if (index > 0)
	{
		write(1, &buffer, index);
		index = 0;
	}
	return (0);
}
/**
 * buffered_write - writes a character to the buffer
 * @c: character to write
 *
 * Return: 1 on success, 0 on failure
 */
int buffered_write(char c)
{
	if (index < 1024)
	{
		buffer[index++] = c;
		return (1);
	}
	else
	{
		flush_buffer();
		buffer[index++] = c;
		return (1);
	}
	return (0);
}
