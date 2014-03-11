all:
	gcc src/utils.c src/selection.c -o bin/selection
	gcc src/utils.c src/insertion.c -o bin/insertion
