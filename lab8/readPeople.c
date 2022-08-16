/**********************************************************************************
 * readPeople.c - Reads people (max 100), fills in array
 *
 * NOTES:
 *  - Input is:
 *    last
 *    first
 *    age
 *   , no blank lines.
 *	- Assume that input is valid (if you find a last name, then there are 2 more lines)
 *  - Input is terminated w/a blank line or EOF
 * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CAP 100

typedef struct
{
	char first[10] ;
	char last[20] ;
	int age ;
} person ;

	// reads people from file handle f, format described above
	// a must be large enough to hold all entries
void readPeople( person* a[], FILE* f ) ;

	// Returns heap memory pointed to by elements of a
	// a is of size n
	// Elements point to a person, or are NULL
void freePeople( person* a[], size_t n ) ;

int main( int argc, char **argv )
{
	FILE *fin = stdin ;

	person* team[CAP] = { NULL } ; /* rest are initialised to 0 */

	if( argc>1 ) {
		fin = fopen( argv[1], "r" ) ;
		if( fin == NULL ) {
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] ) ;
			exit( 1 ) ;
		}
	}

	readPeople( team, fin ) ;

	freePeople( team, CAP ) ;

	return 0 ;
}

/* readPeople function:
Returns void
Reads no more than 100 entries from file
Entries contain first name, last name and age separated by newline
Allocates memory on heap for each entry
Populates a struct for each entry and adds it to given array
Parameters:
	person* a[]: 		Array of pointers to person structs
	FILE* f: 			Opened file pointer to read from */
void readPeople( person* a[], FILE* f ) 
{
	char *buff = NULL ;
	size_t len ;
	size_t cnt = 0 ;

	person *temp;
	while( getline( &buff, &len, f ) > 1 ) 
	{
		// We read a last name (with the newline)
		// - get memory for person
		temp = (person*)malloc(sizeof(*temp));
		printf("Malloc called\n");
		if (!temp) {
			fprintf(stderr, "ERROR: Malloc failed while trying to readPeople\n");
			return;
		}
		// - append to array
		a[cnt] = temp;
		// - copy string name manually since string.h is not included
		for (int i=0; i<len; i++){
			temp->last[i] = buff[i];
		}
		// - read next 2 lines, fill it in 
		getline(&buff, &len, f);
		for (int i=0; i<len; i++){
			temp->first[i] = buff[i];
		}
		getline(&buff, &len, f);
		temp->age = atoi(buff);

		++cnt ;
	}

	free( buff ) ;
}

void freePeople( person* a[], size_t n ) 
{
	// Do NOT assume array is dense.  Check every element
	for (int i=0; i<n; i++) {
		if (a[i] != NULL) {
			free(a[i]);
			a[i] = NULL;
		}
	}
}
