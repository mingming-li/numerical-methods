#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void dft();
int main(int argc, char **argv)
{
double *x,*f,dx,*fnew;
int np,i,n;
double L;
double *T,*A,*a,*b;
FILE *fp;

np=1000;
x=malloc((np+1)*sizeof(double));
f=malloc((np+1)*sizeof(double));
fnew=malloc((np+1)*sizeof(double));
T=malloc(np*sizeof(double));
A=malloc(np*sizeof(double));
a=malloc(np*sizeof(double));
b=malloc(np*sizeof(double));

if(np%2==0)np=np-1;
	

dx=(4.0*M_PI+1.0)/(np-1);

for(i=1;i<=np;i++)
{
	x[i]=(i-1)*dx;
	f[i]=sin(x[i])+sin(2.0*x[i])+sin(3.0*x[i])+2.0*sin(20.0*x[i]);
}

dft(x,f,np,T,A,a,b);

fp=fopen("dft.dat","w");
for(n=1;n<=(np-1)/2;n++)
{
	fprintf(fp,"%f %f\n",T[n],A[n]);
}
fclose(fp);


fp=fopen("fnew.dat","w");
L=(x[np]-x[1])*0.5;
for(i=1;i<=np;i++)
{
	fnew[i]=a[0];
	for(n=1;n<=(np-1)/2;n++)
	{
		if(T[n]>0.0 && T[n]<4000.0)
		{
			fnew[i]+=(a[n]*cos(n*M_PI*x[i]/L)+b[n]*sin(n*M_PI*x[i]/L));
		}
	}
	fprintf(fp,"%f %f %f\n",x[i],f[i],fnew[i]);
}
fclose(fp);

free(x);free(f);
free(T);free(A);
free(a);free(b);
free(fnew);

return 0;
}

void dft(x,f,np,T,A,a,b)
	double *x,*f,*T,*A,*a,*b;
	int np;
{
double dx,L;
int i,n;

dx=x[2]-x[1];
L=(x[np]-x[1])*0.5;

a[0]=0.0;
for(i=1;i<=np-1;i++)
	a[0]+=f[i];
a[0]=a[0]*dx/(2.0*L);

for(n=1;n<=(np-1)/2;n++)
{
	a[n]=0.0;
	b[n]=0.0;
	for(i=1;i<=np-1;i++)
	{
		a[n]+=f[i]*cos(n*M_PI*x[i]/L);
		b[n]+=f[i]*sin(n*M_PI*x[i]/L);
	}
	a[n]=a[n]*dx/L;
	b[n]=b[n]*dx/L;
	T[n]=2.0*L/n;
	A[n]=sqrt(a[n]*a[n]+b[n]*b[n]);
}

return;
}
