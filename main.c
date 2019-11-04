#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#include "pictureManipulation.h"
#include "numberGame.h"

int main(void)
{
	int mat[SIZE][SIZE];

	srand(time(NULL));
	char option;
	int loop = 1;

	while (loop)
	{
		printf(
				"Please choose one of the following options \nP/p - Picture manipulation \n"
						"N/n -Number Game \nE/e -Quit \n");

		scanf("%c", &option);
		option = tolower(option);

		switch (option)
		{
		case 'p':
			pictureManipulationMenu((int*) mat);
			break;
		case 'n':
			NumberGame();
			break;
		case 'e':
			printf("\nBye Bye\n");
			loop = 0;
			break;
		default:
			printf("\nPlease choose valid option!\n");
			break;
		}
		scanf("%c", &option);
	}
	return 1;
}

