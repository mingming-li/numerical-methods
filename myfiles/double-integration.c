#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f();
int main(void)
{
int i,n,j,m;
double a=0.0,b=5.0;//range of x
double c=0.0,d=5.0;//range of y
double h,l;
double Sarea;
double xi,yi;
double g0,g1,g2;
double x,y;
FILE *fp;


fp=fopen("tmp.dat","w");
for(n=2;n<100;n++)
{
	m=n;
	h=(b-a)/(n-1);
	l=(d-c)/(m-1);
	Sarea=0.0;
	for(i=1;i<n;i++)
	{
		xi=a+(i-1)*h;
		g0=g1=g2=0.0;
		for(j=1;j<m;j++)
		{
			yi=c+(j-1)*l;
			g0+=f(xi,yi)+4.0*f(xi,yi+0.5*l)+f(xi,yi+l);
			g1+=f(xi+0.5*h,yi)+4.0*f(xi+0.5*h,yi+0.5*l)+f(xi+0.5*h,yi+l);
			g2+=f(xi+h,yi)+4.0*f(xi+h,yi+0.5*l)+f(xi+h,yi+l);
		}
		Sarea+=g0+4.0*g1+g2;
	}
	Sarea=Sarea*h*l/36.0;
	fprintf(fp,"%d %d %.10f\n",n,m,Sarea);
	fprintf(stdout,"%d %d %.10f\n",n,m,Sarea);
}
fclose(fp);

return 0;
}

double f(x,y)
	double x,y;
{
double value;

//value=exp(x)*y;
value=x*x*x*y*y*y;

return value;
}
