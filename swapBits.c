#include <stdlib.h>
#include <stdio.h>
#define FULLBIT = 0xFFFFFFFF

//These are two of my solutions for question 5.2
//from the book "Elements of Programming Interviews."
//The question requires that one write a function which,
//given a Bit Vector in the form a of a long int and two
//additional ints A and B, swaps the bits in the bitvector
//at positions A and B.
//
//In my second attempt I created a solution with no branches,
//only shifts and arithmetic operations. 
//
//Additionally, this file contains the function *intToBinStr,
//which I made to verify the correctness of my solutions
//by printing the Bit Vector to the terminal.

//FIRST TRY
//TIME COMPLEXITY: O(1)
//SPACE COMPLEXITY: O(1)
long int swapBit(long inBV,short i, short j){
   short a = 1;
   short b;
   short c;
   b = a<<i;
   c = a<<j;
   i = inBV&b;
   j = inBV&c;
   if(i){
      inBV = inBV|c;
   }
   else{
      inBV = inBV&~c;
   }
   if(j){
      inBV = inBV|b;
   }
   else{
      inBV = inBV&~b;
   }        
   
   return inBV;        
}

//SECOND ATTEMPT
//TIME ANALYSIS: o(1) w/ no branches
//SPACE ANALYSIS: o(1)
long int swapBit2(long inBV, short i, short j){
   unsigned int a = 1<<i;
   unsigned int b = 1<<j;
   unsigned int c = ((inBV&a)>>i)<<j;
   unsigned int d = ((inBV&b)>>j)<<i;
   inBV = inBV&(~a);
   inBV = inBV&(~b);
   inBV= inBV+c;
   inBV= inBV+d;

   return inBV;
}

char *intToBinStr(long inInt, char *binStr, int len){
   long bitMask = 1;
   for(int i = len; i >= 0; i--){
      if(inInt&bitMask){
         binStr[i] = '1';
      }
      else{
         binStr[i] = '0';     
      }
      bitMask = bitMask<<1;
   }
   return binStr;
}
 
int main(void){
   char binStr[64];
   int a = 0b10010101;
   for(int i = 0; i < 100000000; i++){
      a = swapBit3(a,0,3);
   }
   printf("%s", intToBinStr((long)a,binStr,64));
    
}
