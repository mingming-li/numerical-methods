#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 
int main(void) 
{ 
 
double upper_bound = 1.0; 
double lower_bound = 0.0; 
int number_of_intervals = 100000; 
double rectangle(); 
double answer; 
 
       //call the rectangle function with the appropriate arguments 
 
       answer=rectangle(upper_bound, lower_bound, number_of_intervals); 
 
       fprintf(stdout,"The answer is: %f\n",answer); 
 
 
return 0; 
} 
 
// RECTANGLE 
// This function computes the integral using rectangle rule 
double rectangle(upper_bound, lower_bound, number_of_intervals) 
    double upper_bound; 
    double lower_bound; 
    int number_of_intervals; 
{ 
 
double h; 
int ii; 
double sum; 
double my_function(); 
double x; 
double answer; 
 
     // h is the size of each interval 
     h = (upper_bound - lower_bound) / (number_of_intervals*1.0); 
 
     sum = 0.0; 
     x = lower_bound; 
 
     for (ii=0; ii <= (number_of_intervals -1); ii++) 
     { 
         sum = sum + h*my_function(x);
         // we increase x to the next value 
         x = x + h; 
     } 
     answer = sum; 
 
return answer; 
} 
 
// MY_FUNCTION 
// This function returns the value of x squared for a given x. 
double my_function(x) 
   double x; 
{ 
double value; 
 
   value = x*x; 
 
return value; 
} 	 
