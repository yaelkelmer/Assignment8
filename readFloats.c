/* Yael Kelmer.
 This code calls reads in to another file that has a list of floats and calculates the mean and standard deviation of all of the floats.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	
	FILE *fileOfFloats;
	fileOfFloats = fopen("floats.txt", "r");
	
	char line[256];
	
	float sum = 0;
	float mean;
	int numberOfFloats = 0;
	while (fgets(line, sizeof(line), fileOfFloats)) {
		float num = strtof(line, NULL);
		sum += num;
		numberOfFloats++;
	}	
	mean = sum / numberOfFloats;
	fclose(fileOfFloats);

	float deviation;
	sum = 0;
	float sqrOfDeviation;
	fileOfFloats = fopen("floats.txt", "r");
	while (fgets(line, sizeof(line), fileOfFloats)) {
		float num = strtof(line, NULL);
		deviation = num - mean;
		sqrOfDeviation = deviation * deviation;
		sum += sqrOfDeviation;
	}
	float variance;
	variance = sum / (numberOfFloats - 1);
	float standardDev;
	standardDev = sqrt (variance);
	printf ("this is the standard deviation: %f\n", standardDev);
}
