#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//find the solution of x^3-3*x+1=0 between (0,1)
 
double f();
void main(void) 
{ 
double x_start,x_end;
double x0,x1,x2,f0,f1,f2;
double x2_new,x2_old;
int i;
 
x_start=0;
x_end=1;

//first iteration
x0=x_start;x1=x_end;
f0=pow(x0,3)-3*x0+1;
f1=pow(x1,3)-3*x1+1;
x2=(x0*f1-x1*f0)/(f1-f0);
f2=pow(x2,3)-3*x2+1;
fprintf(stdout,"%f\n",x2);

//second iteration, update x0 and x1 and get new x2
if(f0*f2<0)
{
	x0=x0;
	x1=x2;
}
else
{
	x0=x2;
	x1=x1;
}
f0=pow(x0,3)-3*x0+1;
f1=pow(x1,3)-3*x1+1;
x2=(x0*f1-x1*f0)/(f1-f0);
f2=pow(x2,3)-3*x2+1;
fprintf(stdout,"%f\n",x2);

//third iteration, update x0 and x1 and get new x2
if(f0*f2<0)
{
	x0=x0;
	x1=x2;
}
else
{
	x0=x2;
	x1=x1;
}
f0=pow(x0,3)-3*x0+1;
f1=pow(x1,3)-3*x1+1;
x2=(x0*f1-x1*f0)/(f1-f0);
f2=pow(x2,3)-3*x2+1;
fprintf(stdout,"%f\n",x2);

//fouth iteration, update x0 and x1 and get new x2
if(f0*f2<0)
{
	x0=x0;
	x1=x2;
}
else
{
	x0=x2;
	x1=x1;
}
f0=pow(x0,3)-3*x0+1;
f1=pow(x1,3)-3*x1+1;
x2=(x0*f1-x1*f0)/(f1-f0);
f2=pow(x2,3)-3*x2+1;
fprintf(stdout,"%f\n",x2);

//for loop

printf("for loop\n");
x_start=0;
x_end=1;

//first iteration
x0=x_start;x1=x_end;
f0=pow(x0,3)-3*x0+1;
f1=pow(x1,3)-3*x1+1;
x2=(x0*f1-x1*f0)/(f1-f0);
f2=pow(x2,3)-3*x2+1;
fprintf(stdout,"%f\n",x2);


for(i=0;i<=20;i++)
{
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	f0=pow(x0,3)-3*x0+1;
	f1=pow(x1,3)-3*x1+1;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)-3*x2+1;
	fprintf(stdout,"%f\n",x2);
}

//modified for loop
printf("modified for loop\n");
x0=x_start;x1=x_end;
for(i=0;i<=20;i++)
{
	f0=pow(x0,3)-3*x0+1;
	f1=pow(x1,3)-3*x1+1;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)-3*x2+1;
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	fprintf(stdout,"%f\n",x2);
}


//modified for loop with condition
printf("modified for loop\n");
x0=x_start;x1=x_end;
x2_old=x0;
for(i=0;i<=20;i++)
{
	f0=pow(x0,3)-3*x0+1;
	f1=pow(x1,3)-3*x1+1;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)-3*x2+1;
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	fprintf(stdout,"%f\n",x2);
	x2_new=x2;
	if(fabs(x2_new-x2_old)<1e-6)
	{
		break;
	}
	x2_old=x2;
}

//while loop and condition
x0=x_start;x1=x_end;
x2_old=x0;
for(i=0;i<=20;i++)
{
	f0=pow(x0,3)-3*x0+1;
	f1=pow(x1,3)-3*x1+1;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)-3*x2+1;
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	fprintf(stdout,"%f\n",x2);
	x2_new=x2;
	if(fabs(x2_new-x2_old)<1e-6)
	{
		break;
	}
	x2_old=x2;
}

//while loop
printf("while loop\n");
x0=x_start;x1=x_end;
x2_old=x0;
while(1)
{
	f0=pow(x0,3)-3*x0+1;
	f1=pow(x1,3)-3*x1+1;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)-3*x2+1;
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	fprintf(stdout,"%f\n",x2);
	x2_new=x2;
	if(fabs(x2_new-x2_old)<1e-6)
	{
		break;
	}
	x2_old=x2;
}

//modified while loop
printf("modified while loop\n");
x0=x_start;x1=x_end;x2=x0;
x2_old=x0;
x2_new=x1;
while(fabs(x2_old-x2_new)>1e-6)
{
	x2_old=x2;
	f0=pow(x0,3)-3*x0+1;
	f1=pow(x1,3)-3*x1+1;
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=pow(x2,3)-3*x2+1;
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	fprintf(stdout,"%f\n",x2);
	x2_new=x2;
}

//modified while loop + function
printf("modified while loop + function\n");
x0=x_start;x1=x_end;x2=x0;
x2_old=x0;
x2_new=x1;
while(fabs(x2_old-x2_new)>1e-6)
{
	x2_old=x2;
	f0=f(x0);f1=f(x1);
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=f(x2);
	if(f0*f2<0)
	{
		x0=x0;
		x1=x2;
	}
	else
	{
		x0=x2;
		x1=x1;
	}
	fprintf(stdout,"%f\n",x2);
	x2_new=x2;
}


//modified while loop + function + clean up variables
printf("modified while loop + function+clearn up variables\n");
x0=x_start;x1=x_end;
x2=x1;
x2_old=x0;
while(fabs(x2-x2_old)>1e-6)
{
	x2_old=x2;
	f0=f(x0);f1=f(x1);
	x2=(x0*f1-x1*f0)/(f1-f0);
	f2=f(x2);
	if(f0*f2<0)
		x1=x2;
	else
		x0=x2;
	fprintf(stdout,"%f\n",x2);
}

} 

double f(x)
	double x;
{
double value;
value=pow(x,3)-3*x+1;
return value;
}
