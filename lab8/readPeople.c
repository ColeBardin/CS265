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
#include <string.h>

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
	for (int i=0; i<CAP; i++){
		if (team[i] != NULL) {
			printf("Member: %s, %s %d\n", team[i]->last, team[i]->first, team[i]->age);
		}
	}
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

	/* Create temp instance of struct */
	person *temp=NULL;
	/* Read newline until EOF */
	while( getline( &buff, &len, f ) > 1 ) 
	{
		/* Allocate memory on HEAP for struct instance */
		temp = malloc(sizeof(*temp));
		/* Add the struct instance pointer to the array */
		a[cnt] = temp;
		/* Use strcpy from string.h to copy the lastname into the struct */
		strcpy(temp->last, buff);

		/* Read next line */
		getline(&buff, &len, f);
		/* Copy firstname into the struct */
		strcpy(temp->first, buff);

		/* Read next line */
		getline(&buff, &len, f);
		/* Convert string to int and insert into struct */
		temp->age = atoi(buff);

		/* Increment count */
		++cnt ;
	}

	free( buff ) ;
}

void freePeople( person* a[], size_t n ) 
{
	/* Iterate i for each index of the array */
	for (int i=0; i<n; i++) {
		/* If element is not NULL (pointer to struct instance */
		if (a[i] != NULL) {
			/* Free it */
			free(a[i]);
			/* Set freed element to NULL */
			a[i] = NULL;
		}
	}
}
