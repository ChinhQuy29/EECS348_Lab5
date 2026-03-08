#include <stdio.h>

#define SIZE 5

// Function prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(const char *title, int matrix[SIZE][SIZE]);

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    
    // Result matrices
    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose1[SIZE][SIZE];
    int transpose2[SIZE][SIZE];

    // Perform matrix operations
    addMatrices(m1, m2, sum);
    multiplyMatrices(m1, m2, product);
    transposeMatrix(m1, transpose1);
    transposeMatrix(m2, transpose2);

    printMatrix("Matrix 1:", m1);
    printMatrix("Matrix 2:", m2);
    printMatrix("Sum of Matrix 1 and Matrix 2:", sum);
    printMatrix("Product of Matrix 1 and Matrix 2:", product);
    printMatrix("Transpose of Matrix 1:", transpose1);
    printMatrix("Transpose of Matrix 2:", transpose2);

    return 0;
}

// This function adds two matrices and stores the result in a third matrix
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// This function multiplies two matrices and stores the result in a third matrix
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// This function transposes a matrix and stores the result in a second matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// This function prints a matrix with a title
void printMatrix(const char *title, int matrix[SIZE][SIZE]) {
    printf("%s\n", title);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}