#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//find the solution of x^3+2*x-5=0
 
void main(void) 
{ 
double x_start,x_end;
double x0,x1,x2,f0,f1,f2;
double x2_new,x2_old;
int i;
 
x0=0;x1=2;
for(i=1;i<=8;i++)
{
	f0=pow(x0,3)+2*x0-5;
	f1=pow(x1,3)+2*x1-5;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)+2*x2-5;
	fprintf(stdout,"Iteration # %d: %.4f %.4f %.4f %.4f %.4f %.4f\n",i,x0,x1,f0,f1,x2,f2);
	if(f0*f2<0)
		x1=x2;
	else
		x0=x2;
}

} 
