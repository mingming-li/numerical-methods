#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//and or

int main(void) 
{ 
 
// Declare 4 integers 
int ii; 
int jj; 
int kk; 
int pp; 
 
// Assign values to the integers. 
// If we want jj and kk to have the same initial value,  
// we can keep them both on the same line. 
 
   ii = - 1; 
   jj = kk = 2; 
   pp = 3; 
 
// Lets check whether any of these are negative integers. 
// We'll use the OR conditional, which is represented as ||. 
 
   if ( (ii < 0) || (jj<0) || (kk<0) || (pp<0) ) 
   { 
       fprintf(stdout,"At least one of these integers is negative.\n"); 
   } 
 
// Lets see if ii is equal to any other integer values. 
// The conditional for "equal to" is == 
 
   if ( (ii == jj) || (ii==kk) || (ii==pp) ) 
   { 
        fprintf(stdout,"Integer ii is equal to another integer\n"); 
   } 
   else 
   { 
        fprintf(stdout,"Integer ii is unique\n"); 
   } 
 
// Lets do the same thing for jj. 
// Lets see if jj is equal to any other integer values. 
// The conditional for "equal to" is == 
 
   if ( (jj == ii) || (jj==kk) || (jj==pp) ) 
   { 
        fprintf(stdout,"Integer jj is equal to another integer\n"); 
   } 
   else 
   { 
        fprintf(stdout,"Integer jj is unique\n"); 
   } 
return 0; 
} 
