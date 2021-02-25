#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double interpolation();

//argc is the number of inputs from command line
int main(int argc,char **argv)
{
int i,n,np;
double *x,*f;
double a,fa;
char string[256];
char fname[256];
FILE *fp;

if(argc<3)
{
	fprintf(stderr,"Usage: ./a.exe,filename, a number\n");
	exit(10);
}

sprintf(fname,"%s",argv[1]);
a=atof(argv[2]);


fp=fopen(fname,"r");
np=0;
while(fgets(string,256,fp)!=NULL)
	np++;

rewind(fp);

n=np-1;
x=malloc(np*sizeof(double));
f=malloc(np*sizeof(double));

for(i=0;i<np;i++)
{
	fgets(string,256,fp);
	sscanf(string,"%lf %lf",&x[i],&f[i]);
}
fclose(fp);


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
		}
	}
	y=y+L*f[j];
}

return y;
}
