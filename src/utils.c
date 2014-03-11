#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int *getListOfInts(int size) {
	// Create a dynamically allocated array
	int *list = malloc(sizeof(int) * size);

	// Initialize the values in the dynamic array
	for(int n=0; n<size; n++)
		*(list + n) = n + 1;

	// return the pointer
	return list;
}

void printList(int *list, int size) {
	for(int n=0; n<size; n++)
		printf("%d\n", *(list + n));
}

// Shuffle algorithm
void shuffle(int *list, int size) {

	// Put seed in randomizer
	srand(time(NULL));

	// walk through the size of the array
	// and randomly swap it with other values
	for(int i=0; i<size; i++) {
		int randomNumber = rand() % size;
		int cachedNumber = *(list + i);
		*(list + i) = *(list + randomNumber);
		*(list + randomNumber) = cachedNumber;
	}
}
