#include <stdio.h>

int main()
{
    int i, j, m, n;

  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &m, &n);
  int a[m][n];

  printf("Enter the elements of matrix A: \n");
  for (i = 0; i < m; i++)
   {
    for (j = 0; j < n; j++) 
    {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &m, &n);

  int b[m][n];

  printf("Enter the elements of matrix B:\n");
  for (i = 0; i < m; i++)
   {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &b[i][j]);
    }
  }

  int c[m][n];

  // Addition of two matrices
  for (i = 0; i < m; i++) 
  {
    for (j = 0; j < n; j++) 
    {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  // Print the resultant matrix
  printf("The resultant matrix is:\n");
  for (i = 0; i < m; i++) 
  {
    for (j = 0; j < n; j++) 
    {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}