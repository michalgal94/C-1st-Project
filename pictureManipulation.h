
#ifndef PICTUREMANIPULATION_H_
#define PICTUREMANIPULATION_H_

#define SIZE 3
#define MAX_RAND_NUM 100
#define MIN_RAND_NUM 1

void pictureManipulationMenu(int* mat);
void initRandommat(int* mat,int rows,int cols);
void swap(int* a, int* b);
void inclockwise(int* mat, int size);
void outclockwise(int* mat, int size);
void fliphorizontal(int* mat,int size);
void flipvertical(int* mat,int size);
void transposeMatrix(int* mat, int size);
void matrix_swap(int* mat, int n1, int m1, int n2, int m2, int rowsize);

#endif /* PICTUREMANIPULATION_H_ */
