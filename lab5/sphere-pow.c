#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

double PI ;

int main( int argc, char* argv[] ) 
{
	PI = 4*atan(1) ;

	double r, V ;

	if( argc<2 )
	{
		fputs( "Need the radius, as an argument.", stderr ) ;
		return 1 ;
	}

	r = atof( argv[1] ) ;

	V = 4 * PI * pow(r, 3) / 3 ;

	printf( "\nThe volume of the sphere with radius %f is %.2e\n\n", r, V ) ;

	return 0 ;
}
		
