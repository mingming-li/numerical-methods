#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double interpolation();

int main(int argc, char **argv)
{
FILE *fp;
double *xobs;
double *fobs;
double x[4],f[4];
double a;
double fa;
int i,k,j,n,degree,np,ishift,ia;
char fname[256],string[256];
char output[256];

sprintf(fname,"%s","HW06.origin.dat");

fp=fopen(fname,"r");
np=0;
while(fgets(string,256,fp)!=NULL)
	np++;
rewind(fp);

xobs=malloc(np*sizeof(double));
fobs=malloc(np*sizeof(double));

for(i=0;i<np;i++)
{
	fgets(string,256,fp);
	sscanf(string,"%lf %lf",&xobs[i],&fobs[i]);
}
fclose(fp);


fp=fopen("HW06.output.dat","w");
for(ia=1;ia<600;ia++)
{
	a=ia*0.1;
	fprintf(fp,"%f ",a);
	for (degree=1;degree<=3;degree++)
	{
		n=degree+1;
		for(i=0;i<np;i++)
		{
			if(xobs[i]>a)
			{
				ishift=-1;
				if(i-1+degree>np-1)//when not enough data is available
				{
					k=(i-1+degree)-(np-1);//how much data points fall outside of the range
					ishift-=k;
				}
				for(j=0;j<n;j++)
				{
					x[j]=xobs[i+j+ishift];
					f[j]=fobs[i+j+ishift];
				}
				break;
			}
		}
		fa=interpolation(n,x,f,a);
		fprintf(fp,"%f ",fa);
	}
	fprintf(fp,"\n",fa);
}

free(xobs);free(fobs);

return 0;
}

double interpolation(n,x,f,a)
        double *x,*f,a;
        int n;
{
double L;
double fa;
int i,j;

fa=0.0;
for(i=0;i<n;i++)
{
        L=1.0;
        for(j=0;j<n;j++)
                if(i!=j)
                        L*=(a-x[j])/(x[i]-x[j]);
        fa+=L*f[i];
}
return fa;
}
