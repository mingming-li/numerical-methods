#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Trapezoid method for integration
// 4 Feb, 2021


double f();


int main(void)
{

        double a, b, h, x1, x2, area;
        int n, i;
	FILE *fp;

        a = 0.;
        b = 1.;
	fp=fopen("tmp.dat","w");
for(n=2;n<1000;n=n+1)
{
        h = (b-a)/(n-1);

        area = 0.;
        for(i=1; i<=n-1; i++)
	{
                x1 = a + (i-1)*h;
                x2 = x1+h;
                area = (f(x1)+f(x2)) + area;
        }
	area=area*h/2;
        fprintf(fp,"%d %f\n",n,area);
}
fclose(fp);
        return 0;
}

double f(x)
	double x;
{
	double y;
	y=pow(x,3.0)+3*x+1;
	return y;
}
