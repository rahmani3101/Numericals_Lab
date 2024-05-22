#include <stdio.h>

// Function to calculate f(x), change this function as needed
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

// Function to perform trapezoidal integration
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // Initial sum with f(a) and f(b)

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);  // Sum of middle terms
    }

    return (h / 2) * sum;  // Final result
}

int main() {
    int a, b;
    int n;

    // Reading the lower and upper limits of integration
    printf("Enter the lower limit of integration (a): ");
    scanf("%d", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%d", &b);
    
    // Reading the number of subintervals
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Calculating the integral using the trapezoidal rule
    double result = trapezoidalRule(a, b, n);
    
    // Printing the result
    printf("The integral from %.2lf to %.2lf is approximately %.5lf\n", a, b, result);

    return 0;
}