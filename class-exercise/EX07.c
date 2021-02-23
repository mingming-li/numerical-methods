#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double interpolation();

int main(void)
{
int i,n,np;
/*
double x[3]={0,1,3};//array index starts from 0 in C
double f[3]={1,3,55};
*/
//another method to define array
double *x,*f;
double a,fa;
char string[256];
FILE *fp;

np=3;
n=np-1;
x=malloc(np*sizeof(double));
f=malloc(np*sizeof(double));

fp=fopen("EX07.dat","r");
for(i=0;i<n;i++)
{
	fgets(string,256,fp);
	sscanf(string,"%lf %lf",&x[i],&f[i]);
}
fclose(fp);

a=0.5;
fa=interpolation(n,x,f,a);
printf("a=%f fa=%f\n",a,fa);

free(x);
free(f);

return 0;
}


double interpolation(n,x,f,a)
	int n;
	double a;
	double *x,*f;
{
double y;
double L;
int i,j;

y=0.0;
for(j=0;j<=n;j++)
{
	L=1.0;
	for(i=0;i<=n;i++)
	{
		if(i!=j)
		{
			L=L*(a-x[i])/(x[j]-x[i]);
			printf("%f %d %d %f %f\n",L,i,j,x[j],x[i]);
		}
	}
	y=y+L*f[j];
}

return y;
}
