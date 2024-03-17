
#include <stdio.h>
#include <math.h>


double f(double x)
{
    return x * x - 10;
}

double fprime(double x) 
{
    return 2 * x;
}


double newton_raphson(double x0, double tol, int max_iter) 
{
    int c = 0;
    double x1 = x0 - f(x0) / fprime(x0);

    while (fabs(f(x1)) > tol && c < max_iter) 
    {
        x0 = x1;
        x1 = x0 - f(x0) / fprime(x0);
        c++;
    }
    return x1;
}

int main() 
{
    double x0, t;
    int max;

    printf("Enter initial approximation: ");
    if (scanf("%lf", &x0) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter tolerance: ");
    if (scanf("%lf", &t) != 1 || t <= 0) 
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter maximum iterations: ");
    if (scanf("%d", &max) != 1 || max <= 0) 
    {
        printf("Invalid input\n");
        return 1;
    }

    double root = newton_raphson(x0, t, max);
    printf("Root: %lf \n", root);
}
