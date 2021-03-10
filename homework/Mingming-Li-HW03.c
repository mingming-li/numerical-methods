#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f();
int main(void)
{
int i,n;
double a=0.0,b=1.0;
double h;
double Rarea,Tarea;
double xi;
double x;
FILE *fp;


fp=fopen("tmp.dat","w");
for(n=2;n<=4096;n=n*2)
{
	h=(b-a)/(n-1);
	Rarea=0.0;
	Tarea=0.0;
	for(i=1;i<n;i++)
	{
		xi=a+(i-1)*h;
		x=xi+h/2.0;
		Rarea+=f(x);
		Tarea+=f(xi)+f(xi+h);
	}
	Rarea*=h;
	Tarea*=h/2.0;
	fprintf(stdout,"n=%d, Rectangle method:%f Trapezoid method:%f\n",n,Rarea,Tarea);
}
fclose(fp);

return 0;
}

double f(x)
	double x;
{
double f;


f=pow(x*(1+pow(x,4.0)),3.0);

//f=pow(x,3.0)+3.0*x+1;
//f=cos(x);

return f;
}
