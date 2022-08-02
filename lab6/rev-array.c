/*********************************************************
 * rev-array.c - reads doubles until blank line or EOF, stores reversed order in array 
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buff = NULL ;
	double arr[100];
	size_t len ;
	int i=0, cnt=0;

	while( getline( &buff, &len, stdin ) > 1 ) {
		arr[cnt] = atof(buff);
		++cnt ;
		if (cnt>10) {
			fprintf(stderr, "ERROR: rev-array given more than 100 numbers\n");
			return -1;
		}
	}
	
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
