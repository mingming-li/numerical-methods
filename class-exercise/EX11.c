#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double Euler();
double S();

int main(int argc,char **argv)
{
int n;
double x0,y0,g0,x1,y1,y1_old;
double diff;

x0=0.0;y0=0.0;g0=0.0;x1=1.0;


y1_old=1000.0;
diff=fabs(y1-y1_old);
n=1;
while(diff>1e-6 || n<10)
{
	y1=Euler(n,x0,y0,g0,x1);

	printf("n=%d y1=%f\n",n,y1);

	diff=fabs(y1-y1_old);

	y1_old=y1;
	n=n*2;
}

return 0;
}

double Euler(n,x0,y0,g0,x1)
	double x0,y0,g0,x1;
	int n;
{
double h,K0,L0;
double x,y,g;
int i;

h=(x1-x0)/n;
x=x0;y=y0;g=g0;
for(i=1;i<=n;i++)
{
	K0=h*g;
	L0=h*S(x,y,g);
	y+=K0;
	g+=L0;
	x+=h;
}
return y;
}



double S(x,y,g)
	double x,y,g;
{
double value;
value=x;
return value;
}
