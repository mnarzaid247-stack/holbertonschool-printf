#include "main.h"
static char buffer[1024];

static int index;

int flush_buffer(void)
{
	if (index > 0)
	{
		write(1, buffer, index);
		index = 0;
	}
	return (0);
}

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
