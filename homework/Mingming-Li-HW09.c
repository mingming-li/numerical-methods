#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double S();
double Euler();
double BackEuler();
double Heun();
double Midpoint();
double RK4();

double S(x,y,g)
        double x,y,g;
{
double value;

value=24*cos(4*x)-16*y;
//value=x;

return value;
}


int main(void)
{
int n;
double x0,y0,g0,x1;
double y,yold;

x0=0.0;y0=0.0;g0=0.0;x1=10.0;

n=1;
y=1.;yold=0.;
while(fabs(y-yold)>1e-5)
{
	yold=y;
	y=RK4(n,x0,y0,g0,x1);
	printf("y(10.0)=%f\n",y);
	n*=2;
}
printf("y(10.0)=%f\n",y);

return 0;

}

double Euler(n,x0,y0,g0,x1)
	int n;
	double x0,y0,x1,g0;
{

double h,K0,x,y,L0,g;
int i;
h=(x1-x0)/n;
x=x0;y=y0;g=g0;
for(i=1;i<=n;i++)
{
	L0=h*S(x,y,g);
	K0=h*g;
	g+=L0;
	y+=K0;
	x+=h;
}
return y;
}

double BackEuler(n,x0,y0,g0,x1)
	int n;
	double x0,y0,g0,x1;
{

double h,K0,x,y,K1,L0,L1,g;
int i;

h=(x1-x0)/n;

x=x0;y=y0;g=g0;

for(i=1;i<=n;i++)
{
	L0=h*S(x,y,g);
	K0=h*g;

	L1=h*S(x+h,y+K0,g+L0);
	K1=h*(g+L0);

	g+=L1;
	y+=K1;

	x+=h;
}
return y;
}

double Heun(n,x0,y0,g0,x1)
	int n;
	double x0,y0,g0,x1;
{

double h,K0,x,y,K1,L0,L1,g;
int i;
h=(x1-x0)/n;
x=x0;y=y0;g=g0;
for(i=1;i<=n;i++)
{
	L0=h*S(x,y,g);
	K0=h*g;

	L1=h*S(x+h,y+K0,g+L0);
	K1=h*(g+L0);

	g+=0.5*(L0+L1);
	y+=0.5*(K0+K1);

	x+=h;
}
return y;
}

double Midpoint(n,x0,y0,g0,x1)
	int n;
	double x0,y0,g0,x1;
{

double h,K0,x,y,K1,L0,L1,g;
int i;
h=(x1-x0)/n;
x=x0;y=y0;g=g0;
for(i=1;i<=n;i++)
{
	L0=h*S(x,y,g);
	K0=h*g;

	L1=h*S(x+0.5*h,y+0.5*K0,g+0.5*L0);
	K1=h*(g+0.5*L0);

	g+=L1;
	y+=K1;

	x+=h;
}
return y;
}

double RK4(n,x0,y0,g0,x1)
	int n;
	double x0,y0,g0,x1;
{

double h,K0,x,y,K1,K2,K3,L0,L1,L2,L3,g;
int i;
h=(x1-x0)/n;
x=x0;y=y0;g=g0;
for(i=1;i<=n;i++)
{
	L0=h*S(x,y,g);
	K0=h*g;

	L1=h*S(x+h*0.5,y+K0*0.5,g+0.5*L0);
	K1=h*(g+0.5*L0);

	L2=h*S(x+h*0.5,y+K1*0.5,g+0.5*L1);
	K2=h*(g+0.5*L1);

	L3=h*S(x+h,y+K2,g+L2);
	K3=h*(g+L2);

	g+=(L0+2.0*L1+2.0*L2+L3)/6.0;
	y+=(K0+2.0*K1+2.0*K2+K3)/6.0;

	x+=h;
}
return y;
}
