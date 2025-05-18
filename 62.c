#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

// Source term g(x,y)
float g(int i, int j, float h)
{
    float x = i * h;
    float y = j * h;
    return 2 * x * x * y * y;
}

int main()
{
    int n, i, j, k, iter, max_iter = 10000;
    float h, tl, tr, tb, tu, error, max_error;
    
    printf("Poisson's Equation Solver (Finite Difference + Gauss-Seidel)\n\n");
    
    printf("Enter number of divisions per side (n): ");
    // The plate has (n+1) nodes per side
    scanf("%d", &n);
    
    printf("Enter grid spacing h: ");
    scanf("%f", &h);
    
    printf("Enter boundary temperatures (left, right, bottom, top): ");
    scanf("%f %f %f %f", &tl, &tr, &tb, &tu);
    
    printf("Enter desired accuracy (e.g., 0.001): ");
    scanf("%f", &error);
    
    int N = (n - 1) * (n - 1); // number of unknowns (internal nodes)
    
    // Allocate arrays dynamically based on N
    float *x_new = (float *)calloc(N, sizeof(float));
    float *x_old = (float *)calloc(N, sizeof(float));
    float *b = (float *)calloc(N, sizeof(float));
    
    if (!x_new || !x_old || !b) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Initialize right-hand side vector b considering source term and boundary conditions
    // Map 2D grid (i,j) with i,j = 1..n-1 internal nodes to 1D index k
    // k = (i-1)*(n-1) + (j-1)
    
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= n - 1; j++) {
            k = (i - 1) * (n - 1) + (j - 1);
            b[k] = h * h * g(i, j, h);
            
            // Add boundary conditions contribution
            
            // left boundary (j=0)
            if (j == 1)
                b[k] += tl;
            // right boundary (j = n)
            if (j == n - 1)
                b[k] += tr;
            // bottom boundary (i=0)
            if (i == 1)
                b[k] += tb;
            // top boundary (i=n)
            if (i == n - 1)
                b[k] += tu;
        }
    }
    
    // Gauss-Seidel Iteration
    iter = 0;
    do {
        max_error = 0.0f;
        
        for (k = 0; k < N; k++) {
            x_old[k] = x_new[k];
        }
        
        for (i = 1; i <= n - 1; i++) {
            for (j = 1; j <= n - 1; j++) {
                k = (i - 1) * (n - 1) + (j - 1);
                float sum = b[k];
                
                // Left neighbor
                if (j > 1)
                    sum += x_new[k - 1];
                else
                    sum += tl;  // boundary
                
                // Right neighbor
                if (j < n - 1)
                    sum += x_new[k + 1];
                else
                    sum += tr;  // boundary
                
                // Bottom neighbor
                if (i > 1)
                    sum += x_new[k - (n - 1)];
                else
                    sum += tb;  // boundary
                
                // Top neighbor
                if (i < n - 1)
                    sum += x_new[k + (n - 1)];
                else
                    sum += tu;  // boundary
                
                sum /= 4.0f;
                
                x_new[k] = sum;
                
                // Track max relative error for convergence
                float local_error = fabs(x_new[k] - x_old[k]);
                if (local_error > max_error)
                    max_error = local_error;
            }
        }
        
        iter++;
        if (iter > max_iter) {
            printf("Max iterations reached without convergence.\n");
            break;
        }
        
    } while (max_error > error);
    
    // Print the solution
    printf("\nSolution (Temperature at internal nodes):\n");
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= n - 1; j++) {
            k = (i - 1) * (n - 1) + (j - 1);
            printf("%8.3f ", x_new[k]);
        }
        printf("\n");
    }
    
    printf("\nNumber of iterations: %d\n", iter);
    
    // Free memory
    free(x_new);
    free(x_old);
    free(b);
    
    return 0;
}
