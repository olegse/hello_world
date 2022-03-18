#include <stdio.h>

#define TRUE  1 /*for using to path function*/
#define FALSE 0 /*for using to path function*/
#define N 9 /*maximum size of matrix*/

typedef int adjmat[N][N]; /*for saving & using matrix*/

void inputToMatrix(adjmat mat); /*fill a matrix*/

void printMatrix(adjmat mat); /*output the matrix with indexes*/

int writeIndex(char typeIndex); /*input indexes u and v*/

int path(adjmat arr, int u, int v); /*checking junction via indexes u and v to matrix recursively*/
