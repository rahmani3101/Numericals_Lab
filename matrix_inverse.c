// This code assumes that the input matrix is square and invertible. 
//If the matrix is not invertible, 
//the inverse function will print an error message.

#include <stdio.h>

// Function to calculate the determinant of a matrix
int determinant(int A[][10], int n);

// Function to calculate the cofactor of matrix A[i][j]
void getCofactor(int A[][10], int temp[][10], int p, int q, int n);

// Function to calculate the adjoint of a matrix
void adjoint(int A[][10], int adj[][10], int n);

// Function to calculate the inverse of a matrix
void inverse(int A[][10], int n);

// Function to print a matrix
void printMatrix(int A[][10], int n);

int main() 
{ 
    int A[10][10], n; 

    // Get the size of the matrix
    printf("Enter the size of the matrix: "); 
    scanf("%d", &n); 

    // Get the elements of the matrix
    printf("Enter the elements of the matrix:\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &A[i][j]); 

    // Find the inverse of the matrix
    inverse(A, n); 
    printf("Inverse of the matrix:\n"); 
    printMatrix(A, n); 

    return 0; 
}

int determinant(int A[][10], int n) {
    int det = 0;
    if (n == 1) {
        return A[0][0];
    } else if (n == 2) {
        return (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    } else {
        int temp[10][10];
        int sign = 1;
        for (int f = 0; f < n; f++) {
            getCofactor(A, temp, 0, f, n);
            det += sign * A[0][f] * determinant(temp, n - 1);
            sign = -sign;
        }
    }
    return det;
}

void getCofactor(int A[][10], int temp[][10], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void adjoint(int A[][10], int adj[][10], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(A, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, n - 1));
        }
    }
}

void inverse(int A[][10], int n) {
    int det = determinant(A, n);
    if (det == 0) {
        printf("The matrix is not invertible.\n");
        return;
    }
    int adj[10][10];
    adjoint(A, adj, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = adj[i][j] / det;
        }
    }
}

void printMatrix(int A[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
