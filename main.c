/*Team WRead -- Piotr Milewski & Victor Teoh
  Systems pd10
  HW07
  2017-10-27*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main(){

  umask(0000);

  int orig[10];
  int copy[10];

  printf("\npopulating orig[] with 10 random numbers\n\n"); 
  populateArray(orig);
  
  printf("Printing out contents of orig[]\n");
  printArray(orig);

  printf("\nWriting numbers to File...\n\n");
  writeToFile( orig, "numbers");
  
  printf("Reading numbers from File...\n\n");
  readFromFile( copy, "numbers");
  
  printf("Printing out contents of copy[]\n");
  printArray(copy);

  return 0;
}
