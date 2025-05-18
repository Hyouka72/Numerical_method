// Runge Kutta Method

#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    // return y * cos(x);
    return x + y;
}

int main()
{
    int i, n;
    float x, y, xp, h, m1, m2, m3, m4;

    printf("\t\t******Runge Kutta Method******\n");
    printf("\nInput initial values of x and y: ");
    scanf("%f%f", &x, &y);
    printf("\nInput x at which y is required: ");
    scanf("%f", &xp);
    printf("\nInput step-size h: ");
    scanf("%f", &h);

    n = (int)((xp - x) / h + 0.5);

    for (i = 1; i <= n; i++)
    {
        m1 = f(x, y);
        m2 = f(x + 0.5 * h, y + 0.5 * m1 * h);
        m3 = f(x + 0.5 * h, y + 0.5 * m2 * h);
        m4 = f(x + h, y + m3 * h);

        x = x + h;
        y = y + (m1 + 2.0 * m2 + 2.0 * m3 + m4) * h / 6.0;
    }

    printf("\nValue of y at x= %f is %f\n", x, y);

    return 0;
}
