#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double p(),q(),r();


int main(void)
{
int i,n;
double a,b,c,d,h;
double *x,*y;

//assign memeory to x and y using the malloc function

//give initial values to array x and y

for(iteration=1;iteration<=10;iteration++)
for(i=1;i<=n-1;i++)
{
	a=1.0;
	b=-2.0-h*p(x[i])+h*h*q(x[i]);
	c=1.0+h*p(x[i]);
	d=h*h*r(x[i]);
	y[i]=(d-a*y[i-1]-c*y[i+1])/b;
}


return;
}

double p(x)
	double x;
{
double value;

value=0.0;

return value;
}

double q(x)
	double x;
{
double value;

value=0.0;

return value;
}

double r(x)
	double x;
{
double value;

value=x;

return value;
}
