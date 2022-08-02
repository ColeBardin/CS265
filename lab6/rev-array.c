/*********************************************************
 * rev-array.c - reads doubles until blank line or EOF, stores reversed order in array 
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX 10

int main()
{
	char *buff = NULL ;
	double arr[ARR_MAX];
	size_t len ;
	int i=0, cnt=0;

	printf("Enter up to 100 doubles:\n");
	/* Read until EOF */
	while( getline( &buff, &len, stdin ) > 1 ) {
		/* If count of given numbers will exceed limits of initial array */
		if (cnt>ARR_MAX-1) {
			fprintf(stderr, "ERROR: rev-array given more than 100 numbers\n");
			printf("Ending input stream and ignoring %lf input\n\n", atof(buff));
			break;
		}
		/* Store values from getline into array */
		arr[cnt] = atof(buff);
		++cnt ;	
	}

	printf("Reversed order is:\n");
	/* Create properly sized array */
	double final[cnt];
	/* Iterate i up to count */
	while (i<cnt) {
		/* Reverse order of items from arr into final */
		final[i] = arr[cnt-i-1];
		i++;
	}
	/* Print out each element of final array */
	for (i=0; i<cnt; i++) {
		printf("%lf\n", final[i]);
	}

	free( buff ) ;
	return 0 ;
}
