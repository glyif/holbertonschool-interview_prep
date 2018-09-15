#include "holberton.h"
#include <stdlib.h>


/**
 * main - main function
 * @argc: arg count
 * @argv: arg array of arrays
 * Return: exit 98 or return 0
 */
int main(int argc, char **argv)
{
	if (argc != 3 || is_digits(argv[1]) == 0 || is_digits(argv[2]) == 0)
	{
		print_string("Error");
		exit(98);
	}

	multiply(argv[1], argv[2]);

	return (0);
}

/**
 * multiply - multiplies 2 string (infinite number)
 * @num1: number 1
 * @num2: number 2
 */
void multiply(char *num1, char *num2)
{
	int num1_length, num2_length, total_length;
	unsigned char *p;
	int *arr;
	int i;
	int j;
	char *s;
	int index;

	if (num1 == NULL || num2 == NULL)
	{
		print_string("Error");
		exit(98);
	}

	num1_length = _strlen(num1);
	num2_length = _strlen(num2);
	total_length = num1_length + num2_length;

	arr = (int *)malloc(sizeof(int) * total_length);

	p = (void *) arr;
	i = sizeof(int) * total_length;

	while (i > 0)
	{
		*p = 0;
		p++;
		i--;
	}
	p = NULL;

	for (i = num1_length - 1; i > -1; i--)
		for (j = num2_length - 1; j > -1; j--)
			arr[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');

	for (i = total_length - 1; i > 0; i--)
	{
		arr[i - 1] += arr[i] / 10;
		arr[i] %= 10;
	}

	s = (char *)malloc(sizeof(char) * (total_length + 1));
	index = 0;
	i = 0;

	if (arr[i] == 0)
		i++;

	while (i < total_length)
		s[index++] = arr[i++] + '0';

	s[index] = '\0';
	print_string(s);
	free(arr);
}

/**
 * _strlen - length of string
 * @string: string
 * Return: lenght of string
 */
int _strlen(char *string)
{
	int i;

	i = 0;

	while (string[i] != '\0')
		i++;

	return (i);
}

/**
 * print_string - prints a string with a new line afterwards
 * @string: string to print
 */
void print_string(char *string)
{
	int i;

	i = 0;

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}

	_putchar('\n');
}

/**
 * is_digits - checks a string to see if its all digits
 * @string: string to check
 * Return: 0 if not all digits, 1 if all digits
 */
int is_digits(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		if ((string[i] < '0') || (string[i] > '9'))
			return (0);

	return (1);
}
