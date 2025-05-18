#include<stdio.h>
#include<math.h>
int main()
{
    printf("~Non-linear Regression (Exponential model)~\n coded by -> Khewang Thing\n");
    int n;
    float a=0,b=0,r,x[10],y[10],sx=0,slny=0,sxlny=0,sx2=0;
    printf("Enter the number of points:\n");
    scanf("%d",&n);
    // taking data
    printf("Enter the value of x and fx(y)\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    // for summations
    for(int i=0;i<n;i++)
    {
        sx=sx+x[i];
        slny=slny+log(y[i]);
        sxlny=sxlny+x[i]*log(y[i]);
        sx2=sx2+x[i]*x[i];
    }
    // Calculating a and b
    b=((n*sxlny)-(sx*slny))/((n*sx2)-(sx*sx));
    r=(slny/n)-(b*sx/n);
    a=exp(r);
    printf("Fitted curve (i.e. y=ae^bx) is:\n y = %0.2fe^%0.2fx",a,b);

return 0;
}
