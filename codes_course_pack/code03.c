#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

//if statements
 
int main(void) 
{ 
 
//you can give variables a value as you declare them 
 
double A=1.0; 
double B=2.0; 
double C=3.0; 
double D=4.0; 
double E=5.0; 
double F=6.0; 
 
// Here is a simple, one line IF statment. 
// Notice the semicolon indicates that the 
// IF statement is finished.  Only the one line 
// IF statements require a semicolon at the end. 
 
     if (B > A) fprintf(stdout,"%f is bigger than %f\n", B,A); 
 
 
// We can add multiple commands to our IF by putting  
// them in brackets. In this example, everything within

// brackets will be done if B is greater than A. 
 
     if (B>A) 
     { 
        fprintf(stdout,"B is bigger than A.\n"); 
        fprintf(stdout,"Thats pretty cool.\n"); 
        fprintf(stdout,"I think A should be +1 bigger though\n"); 
 
        // I change the value of A here to make it equal to itself 
        // plus 1. 
 
         A = A + 1; 
 
         fprintf(stdout,"Now A is %f\n", A); 
     } 
 
// lets create three blank lines in the output 
 
    fprintf(stdout,"\n\n\n"); 
 
// We can also tell our code to do something if the conditional 
// is not true.  We do this by an ELSE. 
 
     if (B>C) 
     { 
        // Because B is not bigger than C,  
        // this should never happen.  Lets put 
        // an error message here and tell the 
        // code to exit if it does happen.    
 
        fprintf(stdout,"You should never be here!\n"); 
        exit(10); 
 
        // exit(10) tells the code to quit. 
     } 
     else 
     { 
        fprintf(stdout,"Cool, I knew C was bigger\n"); 
     } 
// We can make a more complicated structure by including an ELSE IF 
 
     if (C>F) 
     { 
        fprintf(stdout,"We should not be here\n"); 
        exit(10); 
     } 
     else if (C>E) 
     { 
        fprintf(stdout,"We should not be here either\n"); 
        exit(10); 
     } 
     else if (C>D) 
     { 
        fprintf(stdout,"We should not be here either\n"); 
        exit(10); 
     } 
 
else 
     { 
        fprintf(stdout,"You know what? I give up.\n"); 
     } 
 
// We can also nest IF statements. 
// Always be careful with your brackets 
 
     if (B<F) 
     { 
        fprintf(stdout,"B is smaller than F\n"); 
        if (B<E) 
        { 
            fprintf(stdout,"B is also smaller than E\n"); 
            if (B<D) 
            { 
               fprintf(stdout,"B is also smaller than D\n"); 
               if (B<C) 
               { 
                   fprintf(stdout,"B is also smaller than C\n"); 
               } 
            } 
        } 
     } 
 
 
return 0; 
}
