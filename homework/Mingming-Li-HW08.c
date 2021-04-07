#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double S();
double Euler();
double BackEuler();
double Heun();
double Midpoint();
double RK4();

double S(x,y)
        double x,y;
{
double value;

value=(x+y)/x;

return value;
}

int main(void)
{
int n;
double x0,y0,x1;

x0=2.0;y0=2.0;x1=5.0;

for(n=1;n<=10;n++)
{
	printf("%3d %f %f %f %f %f\n",n,Euler(n,x0,y0,x1),BackEuler(n,x0,y0,x1),Heun(n,x0,y0,x1),Midpoint(n,x0,y0,x1),RK4(n,x0,y0,x1));
}

return 0;
}

double Euler(n,x0,y0,x1)
	int n;
	double x0,y0,x1;
{

double h,K0,x,y;
int i;
h=(x1-x0)/n;
x=x0;y=y0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	y+=K0;
	x+=h;
}
return y;
}

double BackEuler(n,x0,y0,x1)
	int n;
	double x0,y0,x1;
{

double h,K0,x,y,K1;
int i;
h=(x1-x0)/n;
x=x0;y=y0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	x+=h;
	K1=h*S(x,y+K0);
	y+=K1;
}
return y;
}

double Heun(n,x0,y0,x1)
	int n;
	double x0,y0,x1;
{

double h,K0,x,y,K1;
int i;
h=(x1-x0)/n;
x=x0;y=y0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	x+=h;
	K1=h*S(x,y+K0);
	y+=0.5*(K0+K1);
}
return y;
}

double Midpoint(n,x0,y0,x1)
	int n;
	double x0,y0,x1;
{

double h,K0,x,y,K1;
int i;
h=(x1-x0)/n;
x=x0;y=y0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	K1=h*S(x+0.5*h,y+0.5*K0);
	x+=h;
	y+=K1;
}
return y;
}

double RK4(n,x0,y0,x1)
	int n;
	double x0,y0,x1;
{

double h,K0,x,y,K1,K2,K3;
int i;
h=(x1-x0)/n;
x=x0;y=y0;
for(i=1;i<=n;i++)
{
	K0=h*S(x,y);
	K1=h*S(x+h*0.5,y+K0*0.5);
	K2=h*S(x+h*0.5,y+K1*0.5);
	K3=h*S(x+h,y+K2);
	y+=(K0+2.0*K1+2.0*K2+K3)/6.0;
	x+=h;
}
return y;
}
