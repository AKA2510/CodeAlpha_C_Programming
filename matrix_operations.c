#include <stdio.h>

#define MAX 10

void readMatrix(int matrix[][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[][MAX], int b[][MAX], int result[][MAX],
               int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(int a[][MAX], int b[][MAX], int result[][MAX],
                    int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;

            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][MAX], int transpose[][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int transpose[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("=== Matrix Operations ===\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter rows and columns: ");
        scanf("%d %d", &r1, &c1);

        if (r1 > MAX || c1 > MAX || r1 <= 0 || c1 <= 0) {
            printf("Invalid matrix size.\n");
            return 0;
        }

        printf("Enter first matrix:\n");
        readMatrix(a, r1, c1);

        printf("Enter second matrix:\n");
        readMatrix(b, r1, c1);

        addMatrix(a, b, result, r1, c1);

        printf("\nAddition result:\n");
        displayMatrix(result, r1, c1);

    } else if (choice == 2) {
        printf("Enter rows and columns of first matrix: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &r2, &c2);

        if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
            r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX) {
            printf("Invalid matrix size.\n");
            return 0;
        }

        if (c1 != r2) {
            printf("Matrix multiplication is not possible.\n");
            return 0;
        }

        printf("Enter first matrix:\n");
        readMatrix(a, r1, c1);

        printf("Enter second matrix:\n");
        readMatrix(b, r2, c2);

        multiplyMatrix(a, b, result, r1, c1, c2);

        printf("\nMultiplication result:\n");
        displayMatrix(result, r1, c2);

    } else if (choice == 3) {
        printf("Enter rows and columns: ");
        scanf("%d %d", &r1, &c1);

        if (r1 <= 0 || c1 <= 0 || r1 > MAX || c1 > MAX) {
            printf("Invalid matrix size.\n");
            return 0;
        }

        printf("Enter matrix:\n");
        readMatrix(a, r1, c1);

        transposeMatrix(a, transpose, r1, c1);

        printf("\nTranspose:\n");
        displayMatrix(transpose, c1, r1);

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
