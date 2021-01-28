#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main(void)
{
double x0,x1,f0,f1,x2,f2;
x0=0.0;
x1=1.0;
while(1)
{
	f0=f(x0);
	f1=f(x1);
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=1;
	printf("x0=%f x1=%f f0=%f f1=%f x2=%f f2=%f\n",x0,x1,f0,f1,x2,f2);
	if (f0*f2<0.0)
		x1=x2;
	else
		x0=x2;
	if(fabs(f2)<1e-6)
		break;
}
return 0;
}
