#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "selection.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: ./selection [size]\n");
    return 0;
  }

  int size = atoi(argv[1]);
  int *list = getListOfInts(size);
  printf("Sorted List:\n");
  printList(list, size);
  shuffle(list, size);
  printf("Shuffled List:\n");
  printList(list, size);
  selectionSort(list, size);
  printf("Selected Sorted List:\n");
  printList(list, size);
  free(list);
}

void selectionSort(int *list, int size) {
  // find the biggest number
  // swap it with the position in the last place
  int big, cache, current;
  for(int i=size; i>0; i--) {
    //printf("First loop.\n");
    big = 0;
    for(int n=0; n<i; n++) {
      //printf("Second loop: %d\n", *(list + n));
      if(*(list + n) > *(list + big)) {
        big = n;
      }
    }
    //printf("Biggest: %d\n", *(list + big));
    cache = *(list + (i-1));
    *(list + (i-1)) = *(list + big);
    *(list + big) = cache;
  }
}
