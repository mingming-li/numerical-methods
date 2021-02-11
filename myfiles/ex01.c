#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 

int main(void) 
{ 
double h, h0, v0, t, g,v;

g=9.8;
h0=1.2;
v0=5.4;
t=0.5;

h=h0+v0*t-0.5*g*t*t;
v=v0-g*t;

fprintf(stdout,"height at %f seconds is %f\n",t,h);
fprintf(stdout,"velocity at %f seconds is %f\n",t,v);
 
return 0; 
} 
