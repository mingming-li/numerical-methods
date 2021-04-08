#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void dft();
int main(int argc, char **argv)
{
double *x,*f,dx;
int np,i,n;
double L;
double *T,*A,*a,*b;
FILE *fp;

np=1000;
x=malloc((np+1)*sizeof(double));
f=malloc((np+1)*sizeof(double));
T=malloc(np*sizeof(double));
A=malloc(np*sizeof(double));
a=malloc(np*sizeof(double));
b=malloc(np*sizeof(double));


dx=0.01;

fp=fopen("fnew.dat","w");
for(i=1;i<=np;i++)
{
	x[i]=(i-1)*dx;
	f[i]=sin(x[i])+cos(x[i]);
	fprintf(fp,"%f %f\n",x[i],f[i]);
}
fclose(fp);

dft(x,f,np,T,A,a,b);

free(x);free(f);
free(T);free(A);
free(a);free(b);

return 0;
}

void dft(x,f,np,T,A,a,b)
	double *x,*f,*T,*A,*a,*b;
	int np;
{

return;
}
