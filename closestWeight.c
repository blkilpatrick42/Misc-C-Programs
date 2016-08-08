#include <stdio.h>
//This is my first solution for question 5.4
//from the book "Elements of Programming Inteviews."
//The question requires that, if each integer were
//assigned a 'weight' determined by the number of
//set bits in its binary representation, (ie 0111=3, 1010 = 2)
//one write a function that is given an integer, and finds
//the nearest integer (less or greater) with the same 'weight'

unsigned getWeight(unsigned a){
   int count = 0;
   while(a){
      a = a ^ (a & ~(a-1));
      count++;
   }
   return count;
}

unsigned closestWeight(unsigned a){
   int diffLow = 0;
   int diffHi = 0;
   int low = 0;
   int hi = 0;
   int i = 1;
   int aWeight = getWeight(a);
   while(!diffLow || !diffHi){
     if(!diffLow&&(a-i)>0){
        if(aWeight==getWeight(a-i)){
           diffLow = i;
           low = (a-i); 
        }
     }
     if(!diffHi){
        if(aWeight==getWeight(a+i)){
           diffHi = i;
           hi = (a+i);
        }
     }
     i++;
   }

   if(diffHi < diffLow){
      return hi;
   }
   else{
      return low;
   }
}


int main(void){
   int b = 6;
   printf("\n%d\n",closestWeight(b));
}
