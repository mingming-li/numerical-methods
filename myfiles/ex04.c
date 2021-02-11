#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f();
int main(void)
{
int i,n;
double a=0.0,b=1.0;
double h;
double area;
double xi;
double x;
FILE *fp;


fp=fopen("tmp.dat","w");
for(n=2;n<=1000;n++)
{
	h=(b-a)/(n-1);
	area=0.0;
	for(i=1;i<n;i++)
	{
		xi=a+(i-1)*h;
		area+=f(xi)+f(xi+h);
	}
	area*=h/2.0;
	fprintf(fp,"%d %f\n",n,area);
	fprintf(stderr,"%d %f\n",n,area);
}
fclose(fp);

return 0;
}

double f(x)
	double x;
{
double f;

f=pow(x,3.0)+3.0*x+1;

return f;
}
