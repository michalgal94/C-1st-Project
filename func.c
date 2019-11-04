#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void printMat(const int* mat, int rows, int cols)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++, mat++)
		{
			printf("%5d ", *mat);
		}
		printf("\n");
	}
	printf("\n");
}

int randomNumber(int min, int max)
{
	return min + (rand() % (max - min + 1));
}


