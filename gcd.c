#include <stdio.h>
#include <stdlib.h>

//This function is an implementation
//of "Euclid's Algorithm," a simple
//and effective algorithm for finding the
//greatest common divisor (GCD) of two
//numbers. 

/* getGCD takes two int parameters
 * "a" and "b," and returns the GCD of
 * the two numbers.
 */
int getGCD(int a, int b){
   int Q = 0; 
   int temp; 

   if(b>a){     
      temp = b;
      a = b;
      b = temp;
   }
   
   do{
      temp = a%b;
      if(temp==0)
         continue;
      a = b;
      b = temp;
   }while(temp>0);

   if(b==1){
      return 0;
   }
   else{
      return b;
   }   
}

/* isCoprime takes two integer
 * parameters "a" and "b" and
 * returns 1 if they are Coprime,
 * and 0 if they are not Coprime.
 */
int isCoprime(int a, int b){
   if(getGCD(a,b) == 1){
      return 1;
   }
  else{
     return 0;
  }
}

int main(void){
   int a = 8;
   int b = 4;
   printf("GCD: %d",getGCD(a,b));
}
