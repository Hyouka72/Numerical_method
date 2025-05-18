#include<stdio.h>

int main()
{
    printf("~Linear Regression~\n coded by -> Khewang Thing\n");
    int n,i;
    float a=0,b=0,x[10],y[10],sx=0,sy=0,sxy=0,sx2=0;
    printf("Enter the number of points:\n");
    scanf("%d",&n);
    printf("Enter the value of x and fx(y)\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    //Calculating the sumations of the need variables
    for(i=0;i<n;i++)
    {
        sx=sx+x[i];
        sy=sy+y[i];
        sxy=sxy+x[i]*y[i];
        sx2=sx2+x[i]*x[i];
    }
    // Calculating a and b
    b=((n*sxy)-(sx*sy))/((n*sx2)-(sx*sx));
    a=(sy/n)-(b*sx/n);
    printf("Fitted line (i.e. y=a+bx) is:\n y = %0.3f + %0.3f x",a,b);
return 0;
}
