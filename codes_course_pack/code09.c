#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 
int main(void) 
{ 
 
// I declare a function as a double function named tell_it_dude. 
 
double tell_it_dude(); 
 
double A=20.0; 
double what_dude_thinks; 
 
       // Call the function "tell_it_dude". 
       // The function has an argument that must be a double 
 
       what_dude_thinks = tell_it_dude(A); 
 
       // Lets prints something to screen to indicate 
       // that we made it back here. 
 
       fprintf(stdout,"Wow, that was a funky function\n"); 
 
       fprintf(stdout,"And the dude says the number should be %f\n",what_dude_thinks); 
 
return 0; 
} 
 
// TELL IT DUDE 
// This is a function that says some cool stuff 
 
double tell_it_dude(some_number) 
     double some_number; 
{ 
 
    fprintf(stdout,"Dude, that number is %f\n",some_number); 
 
    // I think the number should be plus one 
 
    some_number = some_number+1; 
 
return some_number; 
} 
