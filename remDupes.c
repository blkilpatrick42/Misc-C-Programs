#include <stdio.h>
#include <stdlib.h>
/*Algorithm exercise for removing duplicate values
 * from a sorted list. 
 */


/*removes dupes in
 *O(n^2) time
 */
int *remDupes(int *inArray, int len){
   int fillRest = 0;
   for(int i = 0; i < len; i++){
      if(fillRest){
         inArray[i] = 0;
      }
      else if(i+1 < len && inArray[i] == inArray[i+1]){
         for(int n = i; n < len; n++){
            if(n+1 < len)
               inArray[n] = inArray[n+1];
         }
         i--;
      }
      else if(i+1 < len && inArray[i] > inArray[i+1]){
         fillRest = 1;
      }
   }
   return inArray;
}

/*
 * operates in O(n) time
 */
int *remDupes2(int *inArray, int len){
   int cur = 0;
   for(int i = 1; i < len; i++){
      if(inArray[i] > inArray[cur]){
         cur++;
         inArray[cur] = inArray[i];
      } 
   }
   if(cur+1 < len){
      for(int i = cur+1; i < len; i++){
         inArray[i] = 0;
      }
   }
   return inArray;
}

void printArray(int *inArray, int len){
   for(int i = 0; i < len; i++){
     printf(" %d ,",inArray[i]);
   }
   
}

int main(void){
  int testArray[10] = {2,3,5,5,7,11,11,11,13};
  *testArray = *remDupes2(testArray,10);
  printArray(testArray, 10); 

}


