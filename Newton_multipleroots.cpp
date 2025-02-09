#include <stdio.h>
#include <math.h>

// Function to evaluate the cubic polynomial f(x)
double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

// Derivative of the cubic polynomial f'(x)
double df(double x, double a, double b, double c) {
    return 3 * a * x * x + 2 * b * x + c;
}

// Newton-Raphson method to find root
double newtonRaphson(double initialGuess, double a, double b, double c, double d, double tolerance, int maxIterations) {
    double x0 = initialGuess;
    double x1;
    int iter = 0;
    
    while (iter < maxIterations) {
        x1 = x0 - f(x0, a, b, c, d) / df(x0, a, b, c); // Newton-Raphson formula
        
        // Check for convergence
        if (fabs(x1 - x0) < tolerance) {
            printf("Root found at x = %lf after %d iterations\n", x1, iter);
            return x1;
        }
        
        x0 = x1;
        iter++;
    }
    
    printf("Max iterations reached. Root approximation: %lf\n", x0);
    return x0; // Return the current approximation
}

int main() {
    double a, b, c, d;
    
    printf("Enter the coefficients a3, a2, a1, and a0:\n");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    double tolerance = 1e-6;
    int maxIterations = 100;

    // Ask for initial guesses for multiple roots
    int numRoots;
    printf("Enter the number of initial guesses for multiple roots: ");
    scanf("%d", &numRoots);
    
    double initialGuesses[numRoots];
    
    // Get the initial guesses
    for (int i = 0; i < numRoots; i++) {
        printf("Enter initial guess #%d: ", i + 1);
        scanf("%lf", &initialGuesses[i]);
    }

    // Find the roots for each initial guess
    for (int i = 0; i < numRoots; i++) {
        printf("\nFinding root starting with initial guess: %lf\n", initialGuesses[i]);
        newtonRaphson(initialGuesses[i], a, b, c, d, tolerance, maxIterations);
    }

    return 0;
}
