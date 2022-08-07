#include <stdio.h>

void int2string(int n, char answer[]){
	int ndig=1;
	char buff[10];

	
	return;
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
