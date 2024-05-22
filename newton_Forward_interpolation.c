#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to perform Newton forward interpolation
void newtonForwardInterpolation(double x[], double y[], int n, double value) {
    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    double yTable[n][n];
    // Initialize yTable with y values
    for (int i = 0; i < n; i++) {
        yTable[i][0] = y[i];
    }

    // Constructing the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            yTable[j][i] = yTable[j + 1][i - 1] - yTable[j][i - 1];
        }
    }

    double result = y[0];
    double term = 1;
    for (int i = 1; i < n; i++) {
        term *= (u - i + 1) / i;
        result += term * yTable[0][i];
    }

    printf("Interpolated value at %.2lf is %.4lf\n", value, result);
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    double value;
    printf("Enter the value at which interpolation is needed: ");
    scanf("%lf", &value);

    newtonForwardInterpolation(x, y, n, value);

    return 0;
}
