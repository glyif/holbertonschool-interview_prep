#include "palindrome.h"

/**
 * is_palindrome - checks if a unsigned long is a palindrome
 * @n: unsigned long
 * Return: 0 for not palindrome, 1 for palindrome
 */
int is_palindrome(unsigned long n)
{
	unsigned int length = integer_count(n);
	char buffer[21];
	char reverse_buffer[21];
	unsigned int buffer_counter = 0;

	_memreset(buffer, 21);
	_memreset(reverse_buffer, 21);

	_itoa(n, buffer, length);

	reverse(buffer, reverse_buffer, length);


	while (buffer[buffer_counter] != '\0'
		   && reverse_buffer[buffer_counter] != '\0')
	{
		if (buffer[buffer_counter] != reverse_buffer[buffer_counter])
		{
			return (0);
		}
		buffer_counter++;
	}
	return (1);

}

/**
 * integer_count - count how many numbers are in an integer
 * @n: integer to count
 * Return: length of integer
 */
unsigned int integer_count(unsigned long n)
{
	unsigned int length;

	if (n == 0)
		return (1);

	length = 0;

	while (n)
	{
		length++;
		n = n / 10;
	}

	return (length);
}

/**
 * _memreset - modified memreset to reset to '\0'
 * @buffer: buffer
 * @length: length of buffer
 */
void _memreset(char buffer[], unsigned int length)
{
	length--;

	while (length)
	{
		buffer[length] = '\0';
		length--;
	}

	buffer[length] = '\0';
}

/**
 * _itoa - modified implementation of itoa
 * @n: integer to turn into a string
 * @buffer: buffer to right into
 * @length: length of number
 */
void _itoa(unsigned long n, char buffer[], unsigned int length)
{
	length--;

	while (n)
	{
		buffer[length] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
}

/**
 * reverse - reverses a string
 * @buffer: buffer to reverse
 * @reverse_buffer: buffer to reverse
 * @length: length of buffer 1
 */
void reverse(char buffer[], char reverse_buffer[], unsigned int length)
{
	unsigned int buffer_count;

	buffer_count = 0;

	length--;
	while (length)
	{
		reverse_buffer[buffer_count] = buffer[length];
		buffer_count++;
		length--;
	}
	reverse_buffer[buffer_count] = buffer[length];

}

