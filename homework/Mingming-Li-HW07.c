#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double S();

int main(void)
{
int i,n;
double h,K0,K1,x,y;

n=2;
h=1.0/n;
//Euler method
x=0.0;
y=1.0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	y+=K0;
	x+=h;
	printf("Euler method: x=%f K0=%f y=%f\n",x,K0,y);
}
//Backward Euler method
x=0.0;
y=1.0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	x+=h;
	K1=h*S(x,y+K0);
	y+=K1;
	printf("Backward Euler method: x=%f K0=%f K1=%f y=%f\n",x,K0,K1,y);
}

//Heun's method
x=0.0;
y=1.0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	x+=h;
	K1=h*S(x,y+K0);
	y+=0.5*(K0+K1);
	printf("Heun' method: x=%f K0=%f K1=%f y=%f\n",x,K0,K1,y);
}

//Midpoint method
x=0.0;
y=1.0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	K1=h*S(x+h*0.5,y+K0*0.5);
	y+=K1;
	x+=h;
	printf("Midpoint method: x=%f K0=%f K1=%f y=%f\n",x,K0,K1,y);
}
return 0;
}

double S(x,y)
        double x,y;
{
double value;

value=x+y;

return value;
}
