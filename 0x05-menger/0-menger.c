#include "menger.h"

#include <stdio.h>
#include <math.h>

void menger(int level)
{
	int i, j, x, side;

	i = j = x = 0;

	if (level < 0)
	{
		return;
	}

	side = pow(3, level);

	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			x = side / 3;
			while (x)
			{
				if ((i % (x * 3)) / x == 1
					&& (j % (x * 3)) / x == 1)
				{
					break;
				}
				x /= 3;
			}
			if (x)
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}
}
