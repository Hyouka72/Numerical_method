#include <stdio.h>

int main()
{
    printf("~Newton's Divided Difference Interpolation~\n coded by -> Khewang Thing\n");
    int n, i, j;
    float v = 0, p, xv, x[10], fx[10], a[10];

    // Input: Number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input: Value of x for interpolation
    printf("Enter the value of x: ");
    scanf("%f", &xv);

    // Input: Values of x and fx
    for (i = 0; i < n; i++)
    {
        printf("Enter the value of x and fx at i = %d:\n", i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Initialize the divided difference table
    for (i = 0; i < n; i++)
    {
        a[i] = fx[i];
    }

    // Calculate divided differences
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j >= i; j--)
        {
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - i]);
        }
    }

    // Calculate interpolation value
    v = 0;
    for (i = 0; i < n; i++)
    {
        p = 1;
        for (j = 0; j < i; j++)
        {
            p = p * (xv - x[j]);
        }
        v = v + a[i] * p;
    }

    // Output the result
    printf("Interpolation value = %f\n", v);

    return 0;
}