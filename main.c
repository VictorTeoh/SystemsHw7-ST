/*Team WRead -- Piotr Milewski & Victor Teoh
  Systems pd10
  HW07
  2017-10-27*/

#include "rand.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(){

  umask(0000);

  int orig[10];
  int copy[10];

  printf("\npopulating orig[] with 10 random numbers\n\n"); 
  populateArray(orig, sizeof(orig));
  
  printf("Printing out contents of orig[]\n");
  printArray(orig, sizeof(orig));

  printf("\nWriting numbers to File...\n\n");
  writeToFile( orig, "numbers", sizeof(orig));

  printf("Reading numbers from File...\n\n");
  readFromFile( copy, "numbers", sizeof(copy));
  
  printf("Printing out contents of copy[]\n");
  printArray(copy, sizeof(copy));

  return 0;
}
