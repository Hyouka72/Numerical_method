#include<stdio.h>
#include<math.h>
#include<conio.h>
 int a3,a2,a1,a0;
 float func(float x){
    return (a3*pow(x,3)+a2*pow(x,2)+a1*x+a0);

 }
 int main(){
        float x2,x1,x0,E,Era;
        printf("Enter the coefficients a3,a2,a1,a0: ");
        scanf("%d%d%d%d",&a3,&a2,&a1,&a0);
        printf("Enter the initial guess x0, x1 and Error: ");
        scanf("%f%f%f",&x0,&x1,&E);
        while (true)
        {
            x2=x1-(func(x1)*(x1-x0))/(func(x1)-func(x0));
            Era=(x2-x1)/x2;
            if(fabs(Era)<E){
                printf("The root is : %f",x2);
                break;
            }
            x0=x1;
            x1=x2;
        }
        
    getch();
    return 0;
 }