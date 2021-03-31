#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double p(),q(),r();

int main(void)
{
int i,n,k;
// i is the index for nodal points
// k is the index for iteration
// n is the number of sub-intervals
double a,b,c,d,h;
//a, b, c, d are constants
//h is the length of each sub-interval
double *x,*y,*temp_y;

n=10;

//assign memeory to x and y using the malloc function
x=malloc((n+1)*sizeof(double));
y=malloc((n+1)*sizeof(double));
temp_y=malloc((n+1)*sizeof(double));

//define boundary values
x[0]=0.0;
x[n]=1.0;

y[0]=0.0;
y[n]=1.0;

h=(x[n]-x[0])/n;

//give initial values to array x and y
for(i=1;i<=n-1;i++)
{
	x[i]=x[0]+i*h;
	y[i]=0.5*(y[0]+y[n]);
}


for(k=0;k<=1000;k++)
{
//Jacobi method
	for(i=1;i<=n-1;i++)
	{
		a=1.0;
		b=-2.0-h*p(x[i])+h*h*q(x[i]);
		c=1.0+h*p(x[i]);
		d=h*h*r(x[i]);
		temp_y[i]=(d-a*y[i-1]-c*y[i+1])/b;
	}

	for(i=1;i<=n-1;i++)
		y[i]=temp_y[i];

	for(i=0;i<=n;i++)
	{
		printf("x[%d]=%f y[%d]=%f\n",i,x[i],i,y[i]);
	}

}

free(x);
free(y);
free(temp_y);

return 0;
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
