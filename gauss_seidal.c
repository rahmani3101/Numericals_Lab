#include <stdio.h>
#include <math.h>

#define MAX 100
#define EPSILON 0.001

void gaussSeidel(float a[MAX][MAX], float b[MAX], float x[MAX], int n, int maxIterations) {
    int i, j, k;
    float sum, xOld[MAX];

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (k = 0; k < maxIterations; k++) {
        for (i = 0; i < n; i++) {
            xOld[i] = x[i];
        }

        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            x[i] = sum / a[i][i];
        }

        int convergence = 1;
        for (i = 0; i < n; i++) {
            if (fabs(x[i] - xOld[i]) > EPSILON) {
                convergence = 0;
                break;
            }
        }

        if (convergence) {
            printf("Converged in %d iterations.\n", k + 1);
            break;
        }
    }

    if (k == maxIterations) {
        printf("Did not converge in %d iterations.\n", maxIterations);
    }
}

int main() {
    int n, i, j, maxIterations;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    float a[MAX][MAX], b[MAX], x[MAX];

    printf("Enter the coefficients of the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constant terms:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    gaussSeidel(a, b, x, n, maxIterations);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
