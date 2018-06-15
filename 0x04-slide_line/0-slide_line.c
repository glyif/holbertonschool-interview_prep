#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "slide_line.h"

/**
 * squish_line_left - squishes line left
 * @line: line
 * @size: size
 * Return: number of non-zero numbers
 */
int squish_line_left(int **line, size_t size)
{
	size_t position;
	int *hold;
	int *move;
	int total_numbers;

	total_numbers = 0;
	position = 0;
	hold = *line;
	move = *line;

	while (position < size)
	{
		if (*move)
		{
			*hold = *move;
			hold++;
			total_numbers++;
		}

		move++;
		position++;
	}

	return (total_numbers);
}

/**
 * squish_line_right - squishes line right
 * @line: line
 * @size: size
 * Return: number of non-zero numbers
 */
int squish_line_right(int **line, size_t size)
{
	size_t position;
	int *hold;
	int *move;
	int total_numbers;

	total_numbers = 0;
	position = size - 1;
	hold = *line + size - 1;
	move = *line + size - 1;

	while (position < size)
	{
		if (*move)
		{
			*hold = *move;
			hold--;
			total_numbers++;
		}

		move--;
		position--;
	}

	return (total_numbers);
}

/**
 * slide_line_left - slides left
 * @line: line
 * @size: size of line
 * @number_length: numbers in line
 * Return: 1 for success 0 for fail
 */
int slide_line_left(int *line, size_t size, size_t number_length)
{
	int *position = line;
	int *current = line;
	int *next = line;
	size_t next_track = 0;
	size_t p = 0;

	while (p < size && next_track < size)
	{
		next++;
		next_track++;

		if (p >= number_length - 1 && number_length != size)
		{
			line[p] = 0;
			p++;
			continue;
		}

		if (*current == 0)
		{
			*current = *next;
			*next = 0;
			next++;
			next_track++;
		}

		if (*current == *next)
		{
			*position = *current + *next;
			*next = 0;
		}
		p++;
		position++;
		current++;
	}

	while (p < size)
	{
		if (p >= number_length - 1 && number_length != size)
		{
			line[p] = 0;
			p++;
			continue;
		}
		p++;
	}

	return (1);

}

/**
 * slide_line_right - slides right
 * @line: line
 * @size: size of line
 * @number_length: numbers in line
 * Return: 1 for success 0 for fail
 */
int slide_line_right(int *line, size_t size, size_t number_length)
{
	int *position = line + size - 1;
	int *current = line + size - 1;
	int *next = line + size - 1;
	size_t next_track = 0;
	size_t p = size - 1;

	while ((int)p >= 0 && next_track < size)
	{
		next--;
		next_track++;

		if (p <= size - number_length && number_length != size)
		{
			line[p] = 0;
			p--;
			continue;
		}

		if (*current == 0)
		{
			*current = *next;
			*next = 0;
			next--;
			next_track++;
		}

		if (*current == *next)
		{

			*position = *current + *next;
			*next = 0;
		}

		p--;
		position--;
		current--;
	}

	while ((int)p >= 0)
	{
		if (p <= size - number_length && number_length != size)
		{
			line[p] = 0;
			p--;
			continue;
		}
		p--;
	}

	return (1);

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
	size_t number_length = 0;

	if (line == NULL)
	{
		return (0);
	}

	if (direction == SLIDE_LEFT)
	{
		number_length = squish_line_left(&line, size);
		return (slide_line_left(line, size, number_length));
	}

	number_length = squish_line_right(&line, size);

	return (slide_line_right(line, size, number_length));
}
