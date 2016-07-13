/*Yael Kelmer.
 This code creates an array of random integers of the length that the user inputted. Then two functions sort this array of integers in an ascending and descending order and prints all three arrays out.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*I found this code on how to use qsort(). I first thoroughly understood it and then used it for both of these following functions and calling them. http://stackoverflow.com/questions/1787996/c-library-function-to-do-sort */
int compAscend (const void * elem1, const void * elem2) {
	int f = *((int*)elem1);
	int s = *((int*)elem2);
	if (f > s) return 1;
	if (f < s) return -1;
	return 0;
}

int compDescend (const void * elem1, const void * elem2) {
	int f = *((int*)elem1);
	int s = *((int*)elem2);
	if (f < s) return 1;
	if (f > s) return -1;
	return 0;
}

int main()
{

	printf("Please type the amount of integers you want in the array\n");
	int amountOfIntegers;
	scanf ("%d", &amountOfIntegers);

	int *arrayOfInts = (int*) malloc (amountOfIntegers*sizeof(int));
	int i;
	srand(time(NULL));
	for (i = 0; i < amountOfIntegers; i++) {
		arrayOfInts[i] = rand() % 10;
	}
	
	printf("This is the original array: ");
	for (i = 0; i < amountOfIntegers; i++) {
		printf ("%d ", arrayOfInts[i]);
	}
	printf ("\n");


	int *arrayAscend = (int*) malloc (amountOfIntegers*sizeof(int));
	int *arrayDescend = (int*) malloc (amountOfIntegers*sizeof(int));

	for (i = 0; i < amountOfIntegers; i++) {
		arrayAscend[i] = arrayOfInts[i];
	}

	for (i = 0; i < amountOfIntegers; i++) {
		arrayDescend[i] = arrayOfInts[i];
	}

	qsort(arrayAscend, amountOfIntegers, sizeof (*arrayAscend), compAscend);

	printf("This is the array sorted in ascending order: ");
	for (i = 0; i < amountOfIntegers; i++) {
		printf ("%d ", arrayAscend[i]);
	}
	printf("\n");

	qsort(arrayDescend, amountOfIntegers, sizeof (*arrayDescend), compDescend);

	printf ("This is the array sorted in descending order: ");
	for (i = 0; i < amountOfIntegers; i++) {
		printf ("%d ", arrayDescend[i]);
	}
	printf ("\n");
}

