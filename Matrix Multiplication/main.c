/**
*  Program # 2
*  Matrix Array Multiplication using only pointers.
*  CS320
*  10/1/2019
*  @author  Jacob Byerline cssc0457
*/

#include <stdio.h>
#include "p2.h"

#define BUFSIZE 1000

void read_matrices(int **matA, int **matB, int **matC,  int *rowsA, int *colsA_rowsB, int *colB, char *filename){
    
    FILE *DATAfile = fopen(filename, "r");
    
    char * buff = (char*)malloc(BUFSIZE);
    
    int i;
    int matA_rowCount = 0;
    int matB_rowCount = 0;
    int printMe = 1;
    
    for(i = 0; fgets(buff, BUFSIZE - 1, DATAfile) != NULL; i++)
    {
        if( i == 0) {
            *rowsA = atoi(buff);
        }
        else if( i == 1) {
            *colsA_rowsB = atoi(buff);
            *matA = (int *)malloc(*rowsA * *colsA_rowsB * sizeof(int));
        }
        else if( i == 2){
            *colB = atoi(buff);
            *matB = (int *)malloc(*colsA_rowsB * *colB * sizeof(int));
            *matC = (int*)malloc(*rowsA * *colB * sizeof(int));
            printf ("\nMatrix A contents:\n");
        }
        else if( i < *rowsA + 3) {
            printf ("%s", buff);
            int num = 0;
            int j;
            for(j = 0; *(buff + j) != '\0' ; j++){
                if(*(buff + j) != ' ' && *(buff + j) >= '0' && *(buff + j) <= '9'){
                    char tempNum = *(buff + j);
                    num = num * 10;
                    num = num + atoi(&tempNum);
                }
                else if(*(buff + j) == ' '){
                    *(*(matA) + (matA_rowCount)) = num;
                    matA_rowCount++;
                    num = 0;
                }
            }
            *(*(matA) + (matA_rowCount)) = num;
            matA_rowCount++;
        }
        else {
            if (printMe == 1){
                printf("\nMatrix B contents:\n");
                printMe = 0;
            }
            printf ("%s", buff);
            int num = 0;
            int j;
            for(j = 0; *(buff + j) != '\0' ; j++){
                if(*(buff + j) != ' ' && *(buff + j) >= '0' && *(buff + j) <= '9'){
                    char tempNum = *(buff + j);
                    num = num * 10;
                    num = num + atoi(&tempNum);
                }
                else if(*(buff + j) == ' '){
                    *(*(matB) + (matB_rowCount)) = num;
                    num = 0;
                    matB_rowCount++;
                }
            }
            *(*(matB) + (matB_rowCount)) = num;
            matB_rowCount++;
        }
    }
    printf ("\n");
    fclose(DATAfile);
}

void print_matrix(int *prinMat, int numRows, int numCol){
    printf("\nMatrix A * B is:\n");
    int i;
    for(i = 0; i < (numRows * numCol); i++){
        if (i % numCol == 0 && i != 0) printf("\n");
        printf("%d ", *(prinMat + i));
    }
}

void mult_matrices(int *matA, int *matB, int *matC, int rowA, int colA_rowB, int colB){
    int index = 0;
    int i, j, k;
    for(i = 0; i < rowA; i++){
        for(j = 0; j < colB; j++){
            int sum = 0;
            for(k = 0; k < colA_rowB; k++){
                sum = sum + *(matA + k + (i*colA_rowB)) * *(matB + (k * colB) + j);
            }
            *(matC + index) = sum;
            index++;
        }
    }
}

int main(int argc, char ** argv) {
    int *a = NULL, *b = NULL, *c = NULL, row, cola, colb;
    
    printf("Program #2, cssc0547, Jacob Byerline \n");
    
    char file[1000] = "/Users/jacobbyerline/Documents/SDSU/CS 320/Matrix Multiplication/Matrix Multiplication/mm2.txt";
 
    read_matrices(&a, &b, &c, &row, &cola, &colb, file);
    
    //read_matrices(&a, &b, &c, &row, &cola, &colb, *(argv + 1));
    
    mult_matrices(a, b, c, row, cola, colb);
    
    print_matrix(c, row, colb);
    
    printf("\n");
    
    return 0;
}


