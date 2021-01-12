#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//and/or
 
int main(void) 
{ 
 
//declare the variable we will use 
 
double Age_of_Chinle_Formation; 
double Age_of_Dakota_Formation; 
double Age_of_Sundance_Formation; 
 
//we give the age of each rock formation in millions of years 
 
   Age_of_Chinle_Formation = 220.0; 
   Age_of_Dakota_Formation = 100.0; 
   Age_of_Sundance_Formation = 150.0; 
 
// Lets find out which formation is the oldest. 
// There are probably fancier ways to do this, but we'll do it 
// by brute force. 
 
 
// First, lets check Sundance  
   // If Sundance is older than Dakota AND  
   // Sundance is older than Chinle, then it is the oldest. 
 
   if ( (Age_of_Sundance_Formation > Age_of_Dakota_Formation) && 
        (Age_of_Sundance_Formation > Age_of_Chinle_Formation) ) 
   { 
         fprintf(stdout,"The Sundance Formation is the Oldest\n"); 
   } 
   else 
   { 
         fprintf(stdout,"Well, Sundance is not the oldest\n"); 
   } 
 
// Now, lets check Dakota  
   // If Dakota is older than Chinle AND  
   // Dakota is older than Sundance, then it is the oldest. 
   if ( (Age_of_Dakota_Formation > Age_of_Chinle_Formation) && 
        (Age_of_Dakota_Formation > Age_of_Sundance_Formation) ) 
   { 
         fprintf(stdout,"The Dakota Formation is the Oldest\n"); 
   } 
   else 
   { 
         fprintf(stdout,"Well, Dakota is not the oldest\n"); 
   } 
 
// Now, lets check Chinle 
   // If Chinle is older than Dakota AND  
   // Chinle is older than Sundance, then it is the oldest. 
 
   if ( (Age_of_Chinle_Formation > Age_of_Dakota_Formation) && 
        (Age_of_Chinle_Formation > Age_of_Sundance_Formation) ) 
   { 
         fprintf(stdout,"The Chinle Formation is the Oldest\n"); 
   } 
   else 
   { 
         fprintf(stdout,"Well, Chinle is not the oldest\n"); 
   } 
 
return 0; 
} 
