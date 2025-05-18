#include <stdio.h>
#include <math.h>
float f(float x)
{
    //return (x * x) * (cos(x));
    return exp(x);
}
int main()
{
    int n, m, i;
    float a, b, h, sum = 0.0, ics, x;
    printf("\t\t******Composite Simpson's 1/3 ******\n");
    printf("\n Give lower & upper limit of integration a,b: ");
    scanf("%f%f", &a, &b);
    do
    {
        printf("\n Give number of segments n (Even number):");
        scanf("%d", &n);
    } while (n % 2 != 0);
    h = (b - a) / n;
    m = n / 2;
    for (i = 1; i <= m; i++)
    {
        x = a + (2 * i - 1) * h;
        sum = sum + 4 * f(x);
        if (i != m)
            sum = sum + 2 * f(x + h);
    }
    sum = sum + f(a) + f(b);
    ics = sum * h / 3.0;
    printf("\n Integration between %f and %f when h=%f is %f.", a, b, h, ics);

    return 0;
}
