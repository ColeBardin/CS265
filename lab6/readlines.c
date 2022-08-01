/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buff = NULL ;
	size_t len ;
	int cnt = 0;
	double min, max, mean=0.0, curr;
	int flag=0;

	while( getline( &buff, &len, stdin ) > 1 )
	{
		curr = atof(buff);
		++cnt ;
		if (!flag) {
			min=curr;
			max=curr;
			flag=1;
		}
		
		if (curr < min) min=curr;
		if (curr > max) max=curr;
		mean = ( ((double)cnt-1.0)*mean + curr ) / (double)cnt ;
	}

	printf( "\nEnd of input detected.  I read %d lines.\n", cnt ) ;
	printf( "Min:  %lf\nMax:  %lf\nMean: %lf\n", min, max, mean);

	free( buff ) ;
	return 0 ;
}
