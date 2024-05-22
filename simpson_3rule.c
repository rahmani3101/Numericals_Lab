#include <stdio.h>
#include <math.h>

// Define the function to integrate here
double f(double x) {
    return 1 / (1 + x * x);  // Example: Integrating the function 1 / (1 + x^2)
}

double simpsonsOneThirdRule(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Number of intervals must be even.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    return (h / 3) * sum;
}

int main() {
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    double result = simpsonsOneThirdRule(a, b, n);
    if (result != -1) {
        printf("The integral is approximately: %lf\n", result);
    }

    return 0;
}
