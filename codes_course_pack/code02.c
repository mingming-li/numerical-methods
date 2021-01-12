#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 
//data format, print format

int main(void) 
{ 
 
// This is what a comment looks like.  Any text after two dashed lines is 
// ignored by the compiler. 
 
// The first part of a code involves the declaration of variables. 
 
// beginning of declarations 
int number_of_apples, number_of_oranges; 
int number_of_people; 
int total_number_of_fruit; 
 
double apples_per_person; 
double oranges_per_person; 
 
// end of declarations 
 
// lets add some values to variables 
 
     number_of_apples=20; 
     number_of_oranges=15; 
     number_of_people=12; 
 
// lets do some math 
 
     total_number_of_fruit = number_of_apples + number_of_oranges; 
 
     apples_per_person = number_of_apples/number_of_people; 
     oranges_per_person = 
             (number_of_oranges*1.0)/(number_of_people*1.0); 
 
// lets print some results 
 
     fprintf(stdout," There are %d pieces of fruit total\n\n", total_number_of_fruit); 
 
     fprintf(stdout," There are %f apples per person\n", apples_per_person); 
     fprintf(stdout," There are %f oranges per person\n", oranges_per_person);
return 0;
}
