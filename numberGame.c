

#include "func.h"
#include "numberGame.h"
#include <stdlib.h>
#include <stdio.h>



void NumberGame()
{
	int in,valid,*mat,arr[N][M];
	mat = &arr[0][0];
	initmat(mat,N,M);
	int b[N][M] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,0,15}};
    mat = (int*)b;
	BoardShuffle(mat,N,M);
	do
	{
		printMat(mat,N,M);
		do{
			printf("Your Step: ");
			scanf("%d",&in);
			valid = MakeStep(mat,N,M,in);
			if(!valid)
				printf("Invalid Step!\n");
		}while(!valid);
	}while(!CheckForWinner(mat,N,M));
	printf("You win! The game is over!\n");
}

//// Initialize matrix with numbers from 0 to rows*cols
void initmat(int* mat, int rows, int cols)
{
	int i;
	for (i = 0; i < rows * cols; i++, mat++)
	{
		*mat = i;
	}
}

void BoardShuffle(int* board, int n, int m)
{
	int i;
	for(i = 0 ; i < SHUFFLE_COUNT ; i++)
	{
		matrix_swap(board,randomNumber(0, n-1),randomNumber(0, m-1),randomNumber(0, n-1),randomNumber(0, m-1),n);
	}
}

int CheckForWinner(const int* board, int n, int m)
{

	int i,last;
	last = *(board++);
	if(last == 0)return 0;
	for(i = 1 ; i < n*m-1 ; i++,board++)
	{
		if(*board < last)return 0;
		last = *board;
	}
	return 1;
}

int MakeStep(int* board, int n, int m, int num)
{
	int i,j,*start;
	start = board;
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < m ; j++,board++)
		{
			if(*board == 0)
			{
				if(i > 0 && *(board - n) == num){
					matrix_swap(start,i,j,i-1,j,m);
					return 1;
				}else if(i < (n-1) && *(board + n) == num){
					matrix_swap(start,i,j,i+1,j,m);
					return 1;
				}else if(j > 0 && *(board - 1) == num){
					matrix_swap(start,i,j,i,j-1,m);
					return 1;
				}else if(j < (m-1) && *(board + 1) == num){
					matrix_swap(start,i,j,i,j+1,m);
					return 1;
				}
				return 0;

			}
		}
	}
	return 0;
}

// Swap mat[n1][m1] with mat[n2][m2]
void matrix_swap(int* mat, int n1, int m1, int n2, int m2, int rowsize)
{
	int temp = *(mat + n1 * rowsize + m1);
	*(mat + n1 * rowsize + m1) = *(mat + n2 * rowsize + m2);
	*(mat + n2 * rowsize + m2) = temp;
}
