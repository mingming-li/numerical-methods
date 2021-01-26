#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 
int main(void) 
{ 
 
// I declare a function as a void function named tell_it_dude. 
// The compiler sees that this is a function and not a variable 
// because of the parentheses after its name. 
 
void tell_it_dude(); 
 
double A=20.0; 
 
       // Call the function "tell_it_dude". 
       // The function has an argument that must be a double. 
      
       tell_it_dude(A); 
 
       // Lets prints something to screen to indicate 
       // that we made it back here. 
 
       fprintf(stdout,"Wow, that was a funky function\n"); 
 
return 0; 
} 
 
// TELL IT DUDE 
// This is a function that says some cool stuff 
 
void tell_it_dude(some_number) 
     double some_number; 
{ 
 
    fprintf(stdout,"Dude, that number is %f\n",some_number); 
 
 
return; 
} 
