#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//find the solution of x^3-3*x+1=0, read command line
 
double f();
void main(int argc,char **argv) 
{ 
double x0,x1,x2,f0,f1,f2;
double x2_old;
 
x0=atof(argv[1]);
x1=atof(argv[2]);

x2_old=x0;
x2=x1;
while(fabs(x2-x2_old)>1e-6)
{
	x2_old=x2;
	f0=f(x0);f1=f(x1);
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=f(x2);
	if(f0*f2<0)
		x1=x2;
	else
		x0=x2;
	fprintf(stdout,"%f\n",x2);
}

} 

double f(x)
	double x;
{
double value;
value=pow(x,3)-3*x+1;
return value;
}
