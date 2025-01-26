#include <stdio.h>
#include <math.h>

int a3, a2, a1, a0;

// Define the function F(x)
float Fx(float x) {
    return (a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0);
}

// Define the iteration function G(x)
float Gx(float x) {
    return (-a0 / (a3 * pow(x, 2) + a2 * x + a1));
}

int main() {
    float x0, x1, E, Era;

    // Input coefficients
    printf("Enter the coefficients a3, a2, a1, and a0:\n");
    scanf("%d%d%d%d", &a3, &a2, &a1, &a0);

    // Input initial guess and error tolerance
    printf("Enter initial guess (x0) and allowed error (E):\n");
    scanf("%f%f", &x0, &E);

    // Iteration process
    while (1) {
        x1 = Gx(x0); // Calculate the next approximation
        Era = fabs((x1 - x0) / x1); // Calculate the relative error

        // Check if the error is within the tolerance
        if (Era < E) {
            printf("%f is the root.\n", x1);
            break;
        } else {
            x0 = x1; // Update x0 for the next iteration
        }
    }

    return 0;
}
