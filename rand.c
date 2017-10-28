/*Team WRead -- Piotr Milewski & Victor Teoh
  Systems pd10
  HW07
  2017-10-27*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int getRandInt() {
  int rand;
  int randFile = open( "/dev/random", O_RDONLY);
  read( randFile, &rand, sizeof(rand));
  close( randFile);
  return rand;
}

void populateArray( char *array, int size){
  int i = 0;
  for (; i < sizeof(array); i++){
    array[i] = getRandInt();
  }
}

void writeToFile( char *contents, char *name){
  int numbersFile = open(name, O_CREAT | O_RDWR, 0644);
  write(numbersFile, contents, sizeof(contents));
  close(numbersFile);
}
  
void readFromFile( char *copy, char *name){
  int numbersFile = open(name,  O_RDONLY);
  read(numbersFile, copy, sizeof(copy));
  close(numbersFile);
}

void printArray( char *array){
  int i = 0;
  for (; i < sizeof(array); i++){
    printf("random %d: %d\n", i, array[i]);
  }
}
