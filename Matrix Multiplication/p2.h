
#include <stdio.h>
#include <stdlib.h>

/* This function reads m, n, and p from the datafile.
    It then allocates the correct amount of memory required for matrices
    A, B, and C.
    Then matrices A and B are filled from the datafile.
    The values for m, n, and p are passed by reference, and are
    thus filled in by this function
    PARAMETERS in order are:
    int **      matrix A
    int **      matrix B
    int **      matrix C
    int *       m   The number of rows in matrix A
    int *       n   The number of columns in matrix A and
                    The number of rows in matrix B
    int *       p   The number of columns in matrix B
    char *      The name of the datafile, from the command line
*/
void read_matrices(int **, int **, int **,  int *, int *, int *, char *);



/*  This function prints a matrix.  Rows and columns should be preserved.
    PARAMETERS in order are:
    int *       The matrix to print
    int         The number of rows in the matrix
    int         The number of columns in the matrix
*/
void print_matrix(int *, int, int);



/*  The two matrices A and B are multiplied, and matrix C contains the
    result.
    PARAMETERS in order are:
    int *       Matrix A
    int *       Matrix B
    int *       Matrix C
    int         m
    int         n
    int         p
*/
void mult_matrices(int *, int *, int *, int, int, int);
