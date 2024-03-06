#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    int n,i,j;
    
    printf("Enter the size of the matrix: "); 
    scanf("%d", &n); 
    
    int A[n][n];
    int transpose[n][n];

    // Get the elements of the matrix
    printf("Enter the elements of the matrix: \n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &A[i][j]); 

    
    // Find the transpose of the matrix

    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            transpose[i][j] = A[j][i]; 


    // Print the transpose of the matrix

    printf("Transpose of the matrix:\n"); 
    for ( i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
            printf("%d ", transpose[i][j]); 
        printf("\n"); 
    } 

    return 0; 
} 