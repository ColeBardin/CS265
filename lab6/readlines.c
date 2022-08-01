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
	int cnt = 0 ;

	while( getline( &buff, &len, stdin ) > 1 )
	{
		++cnt ;
	}

	printf( "\nEnd of input detected.  I read %d lines.\n", cnt ) ;

	free( buff ) ;
	return 0 ;
}
