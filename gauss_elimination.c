#include <stdio.h>
#include <stdlib.h>

void gaussElimination(float **a, float *b, float *x, int n) {
    int i, j, k, max;
    float tmp;

    for (i = 0; i < n; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (abs(a[j][i]) > abs(a[max][i])) {
                max = j;
            }
        }

        for (j = 0; j < n; j++) {
            tmp = a[i][j];
            a[i][j] = a[max][j];
            a[max][j] = tmp;
        }
        tmp = b[i];
        b[i] = a[max][i];
        a[max][i] = tmp;

        for (j = i + 1; j < n; j++) {
            float factor = a[j][i] / a[i][i];
            for (k = i; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    int n, i, j;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    float **a = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        a[i] = (float *)malloc(n * sizeof(float));
    }
    float *b = (float *)malloc(n * sizeof(float));
    float *x = (float *)malloc(n * sizeof(float));

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

    gaussElimination(a, b, x, n);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);

    return 0;
}
