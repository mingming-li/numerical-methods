#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 
//and or

int main(void) 
{ 
 
// Declare an integer named number. 
int number; 
 
   // Make a loop which varies this integer 
   // from 0 through 20, in multiples of 2. 
 
   for (number = 0; number<=20; number=number+2) 
   { 
       // print out the number 
       fprintf(stdout,"\nNumber is: %d\n",number); 
 
       // Let check whether the number fits into one of the 
       // following categories: 
 
       if (number<5) 
       { 
          fprintf(stdout,"Number is less than 5\n"); 
       } 
       else if ( (number >= 5) && (number <= 10) ) 
       { 
          fprintf(stdout,"Number is between 5 and 10\n"); 
       } 
       else 
       { 
          fprintf(stdout,"Number must be greater than 10\n"); 
       } 
 
       // Lets see if the number is either less than 5 or greater  
       // than 10. 
 
       if ( (number < 5) || (number > 10 && number<6) ) 
       { 
           fprintf(stdout,"This number is either less than 5 or greater than 10\n"); 
       } 
   } 
 
return 0; 
} 
