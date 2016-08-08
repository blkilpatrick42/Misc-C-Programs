#include <stdio.h>
#include <stdlib.h>

/* buildFullArray takes int parameter
 * "length," and constructs an array
 * of "length" size where each index
 * has the value (index+1), thereby
 * creating an array of size "length"
 * containing, in order, numbers in
 * the range 1 to "length"
 */
int *buildFullIntArray(int length){
   int *returnArray = (int*) calloc(length,sizeof(int));
   for(int i = 0; i < length; i++){
      returnArray[i] = i+1;
   }
   return returnArray;
}


/* eSieve takes int parameter "maxNum"
 * and uses and implementation of the
 * "Sieve of Eratosthenes" algorithm
 * to create an array of all prime numbers
 * from 1 to (maxNum)
 */
int *eSieve(int maxNum){
   int *returnArray = buildFullIntArray(maxNum);
   for(int i = 1; i < maxNum; i++){
      if(returnArray[i]){
         for(int x = 2; (x*(i+1)) <= maxNum; x++){
            returnArray[(x*(i+1))-1] = 0;
         }
      } 
   }
   return returnArray;
}


/* printIntArray takes int array
 * paruameter "*inArray" and int parameter
 * "length." It then prints the contents
 * of "*inArray" in order from index 0
 * to index (length-1) in the following format:
 *    
 *   [index+1]) [inArray[index]]
 *
 */
void printIntArray(int *inArray, int length){
   for(int i = 0; i < length; i++){
      printf("\n%d) %d",(i+1),inArray[i]);
   }
}

int main(void){
   int maxNum;
   printf("\nArray Size: ");
   scanf("%d",&maxNum);
   int *testArray  = eSieve(maxNum);
   printIntArray(testArray, maxNum);
   free(testArray);
}
