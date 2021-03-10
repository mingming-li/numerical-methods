#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//define a double function before the main function

double f();

//here is the main function
int main(void)
{
//define variables
int i,n,j,m;
double a,b;
double c,d;
double h,l;
double Sarea;
double xi,yi;
double g0,g1,g2;
double x,y;

//asign values to variables of a, b, c, d, n, and m;
//a=the minimum value of x
//b=the mmaxmum value of x
//c=the minimum value of y
//d=the mmaxmum value of y
//n=# of nodes in x direction
//m=# of nodes in y direction


a=0.0;b=2.0;c=0.0;d=1.0;
n=20;m=20;

//computer the values of h and l;
//h=width of column in x direction
//l=width of column in y direction


h=(b-a)/(n-1);
l=(d-c)/(m-1);


//give an initial zero value to a variable Sarea
//Sarea=the integration
Sarea=0.0;

//put your code BELOW to computer the double integration
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
//put your code ABOVE to computer the double integration

//print out the values of n, m, and Sarea
fprintf(stdout,"n=%d m=%d integration=%f\n",n,m,Sarea);

return 0;
}

double f(x,y)
	double x,y;
{
double value;

//put your function here, where value = f(x,y)
value=exp(x*y);
return value;
}
