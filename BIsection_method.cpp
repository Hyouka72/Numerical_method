#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Define the equation to solve */
#define f(x) (pow(x,2)-4*cos(x))

/* Bisection Method Function */
void bisectionMethod(float x0, float x1, float tol) {
    float x2, f0, f1, f2;
    int step = 1;

    /* Calculate initial functional values */
    f0 = f(x0);
    f1 = f(x1);

    /* Table header */  
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");

    /* Start Bisection Iterations */
    do {
        x2 = (x0 + x1) / 2;  // Midpoint
        f2 = f(x2);

        /* Print the current iteration details */
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, x1, x2, f2);

        /* Update the brackets */
        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step++;
    } while (fabs(f2) > tol);  // Stop when |f(x2)| <= tolerance

    /* Display the root */
    printf("\nRoot is: %.6f\n", x2);
}

int main() {
    float x0, x1, tol;

    /* Clear the console (Optional, based on the environment) */
    system("clear");

    printf("Bisection Method for Solving Non-Linear Equations\n");

    /* Input loop for initial guesses */
    while (1) {
        printf("\nEnter two initial guesses (x0 and x1):\n");
        scanf("%f%f", &x0, &x1);

        printf("Enter tolerable error (e.g., 0.001):\n");
        scanf("%f", &tol);

        /* Check if guesses bracket the root */
        if (f(x0) * f(x1) < 0) {
            break;  // Valid guesses, exit the loop
        } else {
            printf("Incorrect initial guesses. Please try again.\n");
        }
    }

    /* Call the bisection method function */
    bisectionMethod(x0, x1, tol);

    return 0;
}

