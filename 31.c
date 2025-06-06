#include <stdio.h>
#include <math.h>
#define MAX 15

int main()
{
    int i, j, k, n;
    float x[MAX], f[MAX], a[MAX], d[MAX][MAX], xp, dif, sum, p;
    printf("\t\t******Newton's Divided Difference******\n");
    printf("\n Input number of data points:");
    scanf("%d", &n);
    printf("\nInput values of x and f(x) one set on each line:\n");
    for (i = 1; i <= n; i++)
        scanf("%f%f", &x[i], &f[i]);
    for (i = 1; i <= n; i++)
            d[i][1] = f[i];    
    for (j = 2; j <= n; j++)
        for (i = 1; i <= n - j + 1; i++)
            d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j - 1] - x[i]);
    for (j = 1; j <= n; j++)
        a[j] = d[1][j];

    printf("\n Input xp where derivative is required: ");
    scanf("%f", &xp);
    dif = a[2];
    for (k = 3; k <= n; k++)
    {
        sum = 0.0;
        for (i = 1; i <= k - 1; i++)
        {
            p = 1.0;
            for (j = 1; j <= k - 1; j++)
            {
                if (i != j)
                    p = p * (xp - x[j]);
            }
            sum = sum + p;
        }
        dif = dif + a[k] * sum;
    }
    printf("\n Derivative at x=%f is %f.", xp, dif);

    return 0;
}
