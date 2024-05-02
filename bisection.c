#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001

// Function for which we are finding the root
double function(double x) {
    return x*x*x - 2*x - 5; // Example function: x^3 - 2x - 5
}

// Bisection method to find root of the function within the given interval [a, b]
double bisection(double a, double b) {
    double c;

    while ((b - a) >= EPSILON) {
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (function(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main() {
    double a, b; // Interval [a, b] where we search for the root

    printf("Enter the value of a: ");
    scanf("%lf", &a);

    printf("Enter the value of b: ");
    scanf("%lf", &b);

    printf("Root of the given function is: %lf\n", bisection(a, b));
    return 0;
}
