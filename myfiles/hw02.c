#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//find the solution of x^3-2*x+5=0
 
double f();
void main(void) 
{ 
double x_start,x_end;
double x0,x1,x2,f0,f1,f2;
double x2_new,x2_old;
int i;
 
x0=0;x1=2;
x2=x1;
x2_old=x0;
i=0;
while(i<=7)
{
	i++;
	x2_old=x2;
	f0=f(x0);f1=f(x1);
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=f(x2);
	fprintf(stdout,"Iteration # %d: %.4f %.4f %.4f %.4f %.4f %.4f\n",i,x0,x1,f0,f1,x2,f2);
	if(f0*f2<0)
		x1=x2;
	else
		x0=x2;
}

} 

double f(x)
	double x;
{
double value;
value=pow(x,3)+2*x-5;
//value=pow(x,3)-3*x+1;
return value;
}
