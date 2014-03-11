#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "insertion.h" 

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: ./insertion [size]\n");
    return 0;
  }

  int size = atoi(argv[1]);
  int *list = getListOfInts(size);
  
  printf("Sorted List:\n");
  printList(list, size);
  
  shuffle(list, size);
  printf("Shuffled List:\n");
  printList(list, size);

  insertionSort(list, size);
  printf("Insertion Sorted List:\n");
  printList(list, size);
  
  free(list);
}

void insertionSort(int *list, int size) {
  int i, n;
  for(i=0; i<size; i++) { // loop through unsorted
    if(i == 0) { continue; }
    for(n=0; n<=i; n++) { // loop through sorted
      if(*(list + i) <= *(list + n)) {
        break;
      }
    }
    swapWithShift(i, n, list);
  }
}

void swapWithShift(int fromIndex, int toIndex, int *list) {
  int cacheValue = *(list + fromIndex);
  if(fromIndex > toIndex) {
    shiftRight(fromIndex, toIndex, list);
  } else {
    shiftLeft(fromIndex, toIndex, list);
  }
  *(list + toIndex) = cacheValue;
}

void shiftRight(int fromIndex, int toIndex, int *list) {
  for(int i=fromIndex; i>toIndex; i--) {
    if(fromIndex == 0) return;
    *(list + i) = *(list + (i-1));
  }
}

void shiftLeft(int fromIndex, int toIndex, int *list) {
  for(int i=fromIndex; i<toIndex; i++) {
    *(list + i) = *(list + (i+1));
  }
}
