#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "slide_line.h"

void print_array(int *line, size_t size)
{
	size_t length;

	length = 0;

	while (length < size)
	{
		printf("%d, ", *line);
		line++;
		length++;
	}
	printf("\n");
}

int squish_line(int **line, size_t size)
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

	return total_numbers;
}

int slide_line(int *line, size_t size, int direction)
{
	int *position = line;
	int *current = line;
	int *next = line;
	int number_length = 0;
	int p = 0;

	if (direction)
	{
		direction = direction;
	}

	number_length = squish_line(&line, size);

	print_array(line, size);

	while (p < (int) size)
	{
		next++;
		printf("current: %d\n", *current);
		printf("next: %d\n", *next);
		printf("position: %d\n", *position);

		if (p == number_length)
		{
			break;
		}

		if (*current == 0)
		{
			printf("1st if--------\n");
			print_array(line, size);
			*current = *next;
			*next = 0;
			next++;
		}

		if (*current == *next)
		{
			printf("2st if--------\n");
			print_array(line, size);
			*position = *current + *next;
			*next = 0;
		}
		p++;
		position++;
		current++;
	}


	print_array(line, size);
	return 1;
}