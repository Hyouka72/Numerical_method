#include<stdio.h>

int factorial(int n)
{
    if(n==1)
    return 1;
    else
    return(n*factorial(n-1));
}
int main()
{
    printf("~Newton's Forward Difference Interpolation~\n coded by -> Khewang Thing\n");
    int n, i, j;
    float v=0,p,xp,x[10],fx[10],fd[10],h,s;
    printf("Enter the number of points:\n");
    scanf("%d",&n);
    printf("Enter the value at which interpolated value is needed:\n");
    scanf("%f",&xp);
    for (i=0;i<n;i++)
    {
        printf("Enter the value of x and fx at i = %d:\n",i);
        scanf("%f %f",&x[i],&fx[i]);
    }

    h=x[1]-x[0];
    s=(xp-x[0])/h;
    for(i=0;i<n;i++)
    {
        fd[i]=fx[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            fd[j]=fd[j]-fd[j-1]; //forward difference calculation
        }
    }
    v=fd[0];
    for(i=1;i<n;i++)
    {
        p=1;
        for(j=1;j<=i;j++)
        {
            p=p*(s-j+1);
        }
        v=v+(fd[i]*p)/factorial(i); //Interpolation value calculation
    }
    printf("Interpolation value = %f",v);


return 0;
}
