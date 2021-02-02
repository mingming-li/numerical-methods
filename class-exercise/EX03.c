#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
double a,b,h,xi;
double area;
double x;
int i;
int n;

a=0.0;b=1.0;

//define the value of n
n=1000;
h=(b-a)/(n-1);

area=0.0;
for(i=1;i<=n-1;i=i+1)
{
	xi=a+(i-1)*h;
	x=xi+h/2.0;
	area=area+h*(x*x*x+3*x+1);
}
printf("area=%f\n",area);


return 0;
}
