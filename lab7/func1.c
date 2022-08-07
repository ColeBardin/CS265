#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 100

double arrAvg(double *arr, size_t len) {
	size_t i;
	double avg=0;
	/* Sum all recorded values in array */
	for (i=0; i<len; i++) {
		avg+=arr[i];
	}
	/* Divide by their count and return */
	return avg/(double)len;
}

int main(){
	char *buff = NULL;
	size_t len;
	size_t count=0;
	double arr[BUFF_SIZE];

	/* Read from stdin until EOF */	
	while ( getline(&buff, &len, stdin) > 0 ) {
		/* Error handle number of inputs to avoid index error */
		if (count == BUFF_SIZE) {
			fprintf(stderr, "ERROR: Program given more than %d doubles from user\nIgnoring input %lf\n",BUFF_SIZE, atof(buff));
			break;
		}
		/* Save input to array */
		arr[count] = atof(buff);
		/* Increment count */
		count++;
	}

	/* Call arrAvg and print results to stdout */
	printf("Average of array: %lf\n", arrAvg(arr, count));
	return 0;
}
