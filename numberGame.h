
#ifndef NUMBERGAME_H_
#define NUMBERGAME_H_

#define SHUFFLE_COUNT 30
#define N 4
#define M 4

void initmat(int* mat, int rows, int cols);
void NumberGame();
void BoardShuffle(int*,int,int);
int MakeStep(int*,int,int,int);
int CheckForWinner(const int*,int,int);
void matrix_swap(int* mat, int n1, int m1, int n2, int m2, int rowsize);


#endif /* NUMBERGAME_H_ */
