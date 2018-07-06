#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * myprint_grid - print grid
 * @grid: grid to print
 */
void myprint_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sum of 2 sandpiles
 * @grid1: 1st sandpile
 * @grid2: 2nd sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	int b[3][3];

	int n = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
			{
				b[i][j] = 1;
				n++;
			}
			else
				b[i][j] = 0;
		}

	while (n > 0)
	{
		printf("=\n");
		myprint_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (b[i][j] == 1)
				{
					grid1[i][j] -= 4;
					if (i > 0)
						grid1[i - 1][j]++;
					if (j > 0)
						grid1[i][j - 1]++;
					if (i < 2)
						grid1[i + 1][j]++;
					if (j < 2)
						grid1[i][j + 1]++;
				}
			}

		n = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid1[i][j] > 3)
				{
					b[i][j] = 1;
					n++;
				}
				else
					b[i][j] = 0;
	}
}
