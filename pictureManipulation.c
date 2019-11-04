#include "func.h"
#include "pictureManipulation.h"
#include <stdio.h>
#include <stdlib.h>


void pictureManipulationMenu(int* mat)
{
	int choose, loop = 1;

	initRandommat((int*) mat, SIZE, MAX_RAND_NUM);
	printMat((int*) mat, SIZE, SIZE);

	do
	{
		printf(	"Please choose one of the following options \n 1- 90 degree clockwise \n 2- 90 degree counter clockwise "
						" \n 3- fliphorizontal \n 4- flipvertical \n -1- quit\n\n");

		scanf(" %d", &choose);
		switch (choose)
		{
		case 1:
			inclockwise((int*) mat, SIZE);
			printMat((int*) mat, SIZE, SIZE);
			break;
		case 2:
			outclockwise((int*) mat, SIZE);
			printMat((int*) mat, SIZE, SIZE);
			break;
		case 3:
			fliphorizontal((int*) mat, SIZE);
			printMat((int*) mat, SIZE, SIZE);
			break;
		case 4:
			flipvertical((int*) mat, SIZE);
			printMat((int*) mat, SIZE, SIZE);
			break;
		case -1:
			printf("Quit game\n\n");
			loop = 0;
			break;
		default:
			printf("Invalid option, try again");

			break;
		}
	} while (loop);
}


// Initialize matrix with random numbers from 0 to MAX_RAND_NUM
void initRandommat(int* mat, int rows, int cols)
{
	int i;
	for (i = 0; i < rows * cols; i++, mat++)
		*mat = randomNumber(MIN_RAND_NUM, MAX_RAND_NUM);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void inclockwise(int* mat, int size)
{
	transposeMatrix(mat, size);
	flipvertical(mat, size);
}

void outclockwise(int* mat, int size)
{
	flipvertical(mat, size);
	transposeMatrix(mat, size);
}

//swap all rows in matrix
void fliphorizontal(int* mat, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size / 2; j++)
		{
			swap((mat + i), (mat + (size - 1) * size + i));
		}
	}
}

//swap all columns in matrix
void flipvertical(int* mat, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size / 2; j++)
		{
			swap((mat + (size * i) + j), (mat + (size * i) + size - 1 - j));
		}
	}
}

void transposeMatrix(int* mat, int size)
{
	int i, j; //, temp;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			swap(mat + size * i + j, mat + size * j + i);
		}
	}
}



