#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//for loops
 
int main(void) 
{ 
 
int kk; 
 
for (kk=1; kk <= 10; kk=kk+1) 
{ 
    fprintf(stdout,"the value of kk is %d\n",kk); 
} 
 
fprintf(stdout,"Another loop\n"); 
 
for (kk=25; kk > 14; kk=kk-1) 
{ 
    fprintf(stdout,"the value of kk is %d\n",kk); 
} 
 
fprintf(stdout,"Another loop\n"); 
 
// kk=kk+1 can also be represented as simply kk++   
// so we could also write this: 
 
for (kk=1; kk <= 5; kk++) 
{     fprintf(stdout,"the value of kk is %d\n",kk); 
} 
 
fprintf(stdout,"Another loop\n"); 
 
// kk=kk-1 can also be represented as kk--   
// so we could also write this: 
 
for (kk=1; kk > -3; kk--) 
{ 
    fprintf(stdout,"the value of kk is %d\n",kk); 
} 
 
return 0; 
} 
