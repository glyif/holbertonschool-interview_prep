#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "slide_line.h"


/**
 * slide_line_left - slides left
 * @line: line
 * @size: size of line
 */
void slide_line_left(int *line, size_t size)
{
	int *a = line;
	size_t i;
	size_t pos = 0;

	for (i = 1; i < size; i++)
	{
		if (a[i] != 0)
		{
			if (a[pos] == 0)
			{
				a[pos] = a[i];
				if (i != pos)
					a[i] = 0;
			}
			else if (a[i] == a[pos])
			{
				if (pos != i)
				{
					a[pos] += a[i];
					a[i] = 0;
					pos++;
				}
			}
			else
			{
				pos++;
				if (i != pos)
				{
					a[pos] = a[i];
					a[i] = 0;
				}
			}
		}
	}
}

/**
* invert - invert the elements of the line
* @line: line
* @size: size of line
*/
void invert(int *line, size_t size)
{
	size_t i;
	int aux;
	int *a = line;

	for (i = 0; i < size / 2; i++)
	{
		aux = a[i];
		a[i] = a[size - 1 - i];
		a[size - 1 - i] = aux;
	}
}

/**
 * slide_line - slides line
 * @line: line
 * @size: size of line
 * @direction: left or right slide
 * Return: 1 for success 0 for fail
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL
		|| size <= 0
		|| (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		slide_line_left(line, size);
	else
	{
		invert(line, size);
		slide_line_left(line, size);
		invert(line, size);
	}
	return (1);
}
