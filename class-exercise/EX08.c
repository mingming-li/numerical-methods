#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double interpolation();

//argc is the number of inputs from command line
int main(int argc,char **argv)
{
int i,n,np;
double *x,*f;
double xsub[4],fsub[4];
double a,fa;
char string[256];
char fname[256];
FILE *fp;


if(argc<2)
{
	fprintf(stderr,"Usage: ./a.exe,filename\n");
	exit(10);
}

sprintf(fname,"%s",argv[1]);

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

fp=fopen("EX08.output3.dat","w");
for(a=0.0;a<=3.1;a=a+0.01)
{
	for(i=0;i<np;i++)
	{
		if(x[i]>a)
		{
			if(i>30)
			{
				xsub[0]=x[i];
				xsub[1]=x[i-1];
				xsub[2]=x[i-2];
				xsub[3]=x[i-3];
				fsub[0]=f[i];
				fsub[1]=f[i-1];
				fsub[2]=f[i-2];
				fsub[3]=f[i-3];
			}
			else
			{
				xsub[1]=x[i];
				xsub[0]=x[i-1];
				fsub[1]=f[i];
				fsub[0]=f[i-1];
				xsub[2]=x[i+1];
				fsub[2]=f[i+1];
				xsub[3]=x[i+2];
				fsub[3]=f[i+2];
				break;
			}
		}
	}
	fa=interpolation(3,xsub,fsub,a);
	printf("a=%f fa=%f\n",a,fa);
	fprintf(fp,"%f %f\n",a,fa);
}
fclose(fp);

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
