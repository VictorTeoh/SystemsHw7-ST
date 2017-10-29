/*Team WRead -- Piotr Milewski & Victor Teoh
  Systems pd10
  HW07
  2017-10-27*/

#include "rand.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

//returns a random integer utilizing /dev/random
int getRandInt() {
  int rand;
  int randFile = open( "/dev/random", O_RDONLY);
  if (randFile == -1){
    printf("no /dev/random file\n");
    exit(0);
  }
  read( randFile, &rand, sizeof(rand));
  close( randFile);
  return rand;
}

//populates an array with random ints
//takes in an array pointer and the size in bytes of the array
void populateArray( int *array, int size){
  int i = 0;
  for (; i < size/sizeof(int); i++){
    array[i] = getRandInt();
  }
}

//writes an array to a file
//takes in an array pointer, the name of the file, and the size in bytes of the array
void writeToFile( int *contents, char *name, int size){
  int numbersFile = open(name, O_CREAT | O_RDWR, 0644);
  write(numbersFile, contents, size);
  close(numbersFile);
}
  
//reads the file into an array
//takes in an array pointer, the name of the file, and the size in bytes of the array
void readFromFile( int *copy, char *name, int size){
  int numbersFile = open(name, O_RDONLY);
  read(numbersFile, copy, size);
  close(numbersFile);
}

//prints out the contents of an array
//takes in an array pointer and the size in bytes of the array
void printArray( int *array, int size){
  int i = 0;
  for (; i < size/sizeof(int); i++){
    printf("random %d: %d\n", i, array[i]);
  }
}
