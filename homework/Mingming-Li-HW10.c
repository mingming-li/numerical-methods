#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double p(),q(),r();
void Jacobi(),Gauss_Seidel();

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
value=-4.0;
return value;
}

double r(x)
	double x;
{
double value;
value=3*x;
return value;
}

void Jacobi(n,x,y)
	int n;
	double *x,*y;
{

double a,b,c,d,h,*ytemp,residual,temp;
int i,j;


printf("Jacobi method\n");

h=(x[n]-x[0])/n;

ytemp=malloc((n+1)*sizeof(double));

for(i=1;i<n;i++)
{
	x[i]=x[0]+i*h;
	y[i]=0.5*(y[0]+y[n]);
}


j=0;
while(1)
{
	for(i=1;i<n;i++)
	{
		a=1.0;
		b=-2.0-h*p(x[i])+h*h*q(x[i]);
		c=1+h*p(x[i]);
		d=h*h*r(x[i]);
		ytemp[i]=(d-a*y[i-1]-c*y[i+1])/b;
	}


	residual=0.0;
	for(i=1;i<n;i++)
	{
		temp=fabs(y[i]-ytemp[i]);
		if(temp>residual)
			residual=temp;
	}

	if(residual<1e-6)
		break;

	for(i=1;i<n;i++)
		y[i]=ytemp[i];

	j++;
}
printf("%d iterations used\n",j);

free(ytemp);

return;
}

void Gauss_Seidel(n,x,y)
	int n;
	double *x,*y;
{
double a,b,c,d,h,residual,*ytemp,temp;
int i,j;

printf("Gauss_Seidel method\n");

h=(x[n]-x[0])/n;

ytemp=malloc((n+1)*sizeof(double));

for(i=1;i<n;i++)
{
	x[i]=x[0]+i*h;
	y[i]=0.5*(y[0]+y[n]);
}

j=0;
while(1)
{
	for(i=1;i<n;i++)
		ytemp[i]=y[i];

	for(i=1;i<n;i++)
	{
		a=1.0;
		b=-2.0-h*p(x[i])+h*h*q(x[i]);
		c=1+h*p(x[i]);
		d=h*h*r(x[i]);
		y[i]=(d-a*y[i-1]-c*y[i+1])/b;
	}

	residual=0.0;
	for(i=1;i<n;i++)
	{
		temp=fabs(y[i]-ytemp[i]);
		if(temp>residual)
			residual=temp;
	}

	if(residual<1e-6)
		break;


	j++;
}
printf("%d iterations used\n",j);

free(ytemp);

return;
}

int main(int argc,char **argv)
{
int n,i,j,method;
double *y,*x;
double a,b,c,d,h;

method=atoi(argv[1]);

n=10;

x=malloc((n+1)*sizeof(double));
y=malloc((n+1)*sizeof(double));

x[0]=0.0;x[n]=1.0;
y[0]=0.0;y[n]=1.0;

if(method==1)
	Jacobi(n,x,y);
else if(method==2)
	Gauss_Seidel(n,x,y);
for(i=0;i<=n;i++)
	printf("x[%2d]=%.2f y[%2d]=%.3f\n",i,x[i],i,y[i]);


free(x);
free(y);
return 0;
}
