#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function, read and write files

double f();


int main(void)
{

double a, b, h, x1, x2, area;
int n, i;
FILE *fpin,*fpout;
char string[256];

n=1000;
fpin=fopen("EX05.input.dat","r");
if(fpin==NULL)
{
	fprintf(stdout, "Cannot find file\n");
	exit(10);
}
fpout=fopen("EX05.output.dat","w");
while(fgets(string,256,fpin)!=NULL)
{
	sscanf(string,"%lf %lf",&a,&b);
	h = (b-a)/(n-1);

	area = 0.;
	for(i=1; i<=n-1; i++)
	{
		x1 = a + (i-1)*h;
		x2 = x1+h;
		area = (f(x1)+f(x2)) + area;
	}
	area=area*h/2;
	fprintf(fpout,"%.2f %.2f %.2f\n",a,b,area);
}
fclose(fpout);
fclose(fpin);


return 0;
}

double f(x)
	double x;
{
	double y;
	y=pow(x,3.0)+3*x+1;
	return y;
}
