#include <stdio.h>

//This is my first attempt solution to problem 5.5 
//from the book "Elements of Programming Interviews."
//The problem requires that one create a function
//that multiplies two positive 32 bit integers using only
//-assignment operators
//-bitwise operators >>,<<,|,&,~,^
//-equality checks and boolean operations thereof
//-loops and functions that you write yourself

unsigned bitwiseAdd(unsigned x, unsigned y){
   unsigned mask = 1;
   unsigned endMask = mask << 31;
   unsigned r = 0;
   unsigned i = 0;
   unsigned carry = 0;
   while(mask!=endMask){
      if(mask&(x^y)){
         if(!carry){
            r = r|mask; 
         }
      }
      else{
         if(carry == 1){
            r = r|mask;
            carry = 0;
         }
         if(mask&(x&y)){
            carry = 1;
         }
      }
      mask = mask << 1;
   }
   
   return r;
}

unsigned bitwiseMult(unsigned x, unsigned y){
    unsigned long r = 0;
    unsigned mask = 1;
    unsigned i = 0;
    while(i!=32){
       if(mask&y){
          r = bitwiseAdd(r,(x<<i));
       }
       i = bitwiseAdd(i,1);
       mask = mask << 1;
    }

    return r;
}

int main(void){
   int a = 5;
   int b = 101;
   printf("Product of %d and %d is %d",a,b,bitwiseMult(a,b));
   
}
