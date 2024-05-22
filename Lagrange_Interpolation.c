#include <stdio.h>

// Function to implement Lagrange Interpolation
double lagrangeInterpolation(double x[], double y[], int n, double value) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    double value;
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &value);

    double result = lagrangeInterpolation(x, y, n, value);
    printf("Interpolated value at x = %.2lf is %.2lf\n", value, result);

    return 0;
}