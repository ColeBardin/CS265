/* 
 * uninit - check to see which compilers do what with unitialised variables
 *
 * OCT 2020
 *
 */

#include <stdio.h>

int gi ;
double gx ;

int main( int argc, char* argv[] ) 
{
	int i ;
	double x ;

	printf( "Globals:  gi is %d, and gx is %f\n", gi, gx ) ;
	printf( "Locals:  i is %d, and x is %f\n", i, x ) ;

	return 0 ;
}
		
