#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(x)
	double x;
{
	return 1.0;
}

double func2(x)
	double x;
{
	return x;
}

double func3(x)
	double x;
{
	return cos(M_PI*x);
}


int main(int argc, char **argv)
{
double (*f[4])();
int m;
double *a,*temp_a,*B,**A,*x,*y,temp1,temp2,diff,temp,*ymod,xc,fc;
double R2;
int i,j,n,l;
char string[256],fname[256];
FILE *fp;

m=1;
f[1]=func1;
f[2]=func2;
f[3]=func3;

a=malloc((m+1)*sizeof(double));
temp_a=malloc((m+1)*sizeof(double));
B=malloc((m+1)*sizeof(double));

A=malloc((m+1)*sizeof(double *));
for(i=1;i<=m;i++)
	A[i]=malloc((m+1)*sizeof(double));

if(argc<2)
{
        fprintf(stderr,"Usage: ./a.exe,filename\n");
        exit(10);
}

sprintf(fname,"%s",argv[1]);

fp=fopen(fname,"r");
n=0;
while(fgets(string,256,fp)!=NULL)
        n++;

rewind(fp);

x=malloc((n+1)*sizeof(double));
y=malloc((n+1)*sizeof(double));
ymod=malloc((n+1)*sizeof(double));

for(i=1;i<=n;i++)
{
        fgets(string,256,fp);
        sscanf(string,"%lf %lf",&x[i],&y[i]);
}
fclose(fp);


//construct matrix A and B

for(i=1;i<=m;i++)
{
	for(j=1;j<=m;j++)
	{
		A[i][j]=0.0;
		for(l=1;l<=n;l++)
		{
			A[i][j]+=(*f[i])(x[l]) * (*f[j])(x[l]);
		}
	}
	B[i]=0.0;
	for(l=1;l<=n;l++)
	{
		B[i]+=y[l]*(*f[i])(x[l]);
	}
}


//initial condition
for(i=1;i<=m;i++)
{
	a[i]=1.0;
}


//Gauss-Seidel
while(1)
{
	//hold old a values
	for(i=1;i<=m;i++)
		temp_a[i]=a[i];

	//update a values
	for(i=1;i<=m;i++)
	{
		temp1=0.0;
		for(j=i+1;j<=m;j++)
		{
			temp1+=A[i][j]*a[j];
		}

		temp2=0.0;
		for(j=1;j<=i-1;j++)
		{
			temp2+=A[i][j]*a[j];
		}

		a[i]=(B[i]-temp1-temp2)/A[i][i];
	}

	//condition of convergency
	diff=0.0;
	for(i=1;i<=m;i++)
	{
		temp=fabs(a[i]-temp_a[i]);
		if(temp>diff)
			diff=temp;
	}

	if(diff<1e-6)
	{
		break;
	}

		
}

for(i=1;i<=n;i++)
{
	ymod[i]=0.0;
	for(j=1;j<=m;j++)
	{
		ymod[i]+=a[j]*(*f[j])(x[i]);
	}
}

temp1=0.0;
for(i=1;i<=n;i++)
{
	temp1+=pow((y[i]-ymod[i]),2.0);
}

temp=0.0;
for(i=1;i<=n;i++)
{
	temp+=y[i];
}
temp/=n;

temp2=0.0;
for(i=1;i<=n;i++)
{
	temp2+=pow((y[i]-temp),2.0);
}

R2=1.0-temp1/temp2;


printf("a1=%f a2=%f a3=%f R2=%f\n",a[1],a[2],a[3],R2);

sprintf(fname,"%s.fit",fname);
fp=fopen(fname,"w");
for(xc=x[1];xc<=x[n];xc+=0.01)
{
	fc=0.0;
	for(i=1;i<=m;i++)
	{
		fc+=a[i]*(*f[i])(xc);
	}
	fprintf(fp,"%f %f\n",xc,fc);

}
fclose(fp);


free(x);
free(y);
free(a);
free(temp_a);
free(B);

for(i=1;i<=m;i++)
	free(A[i]);
free(A);


return 0;
}
