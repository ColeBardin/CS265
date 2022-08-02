#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input;
int curr;

void usage() {
	fprintf(stderr, "Usage: ./msg [input filename]\n");
	return;
}

int check_foo() {
	int valid=1; /* 1 for valid message. 0 for invalid */
	int state=2; /* initial state is 2 to follow FSM in guidlines */
	
	/* Print out type char */
	putchar(curr);
	while(1) {
		/* Get the next input */
		curr = getc(input);

		/* If char is EOF or a newline */ 
		if (curr==EOF | curr=='\n') return valid; /* Return validity and exit check */
		else putchar(curr); /* If not, just print the character */

		/* While the sequence is still considered valid */
		if (valid) {
			/* For given inputs */
			switch (curr) {
			/* For inputs 1, 2, and 3 */
			case '0': 
			case '1':
			case '2':
				if (state==2) state=3; /* Change state 2 to 3 */
				else if (state==3) state=3; /* Remain at state 3 */
				else if (state==4) valid=0; /* Invalid entry for state 4 */
				break;
			case 'F': /* For input of F */
				if (state==2) valid=0; /* Invalid entry for state 2 */
				else if (state==3) state=4; /* Change state from 3 to 4 */
				else if (state==4) valid=0; /* Invalid entry for state 4 */
				break;
			default: /* Other characters are invalid */
				valid=0;
				break;
			}
		}
	}
}

int check_eep() {
	int valid=1; /* 1 for valid message. 0 for invalid */
	int state=2; /* initial state is 2 to follow FSM in guidlines */
	
	/* Print out type char */
	putchar(curr);
	while(1) {
		/* Get the next input */
		curr = getc(input);

		/* If char is EOF or a newline */ 
		if (curr==EOF | curr=='\n') return state==2?valid:0; /* If state is two, return validity, else return INVALID */
		else putchar(curr); /* If not, just print the character */

		/* While the sequence is still considered valid */
		if (valid) {
			/* For given inputs */
			switch (curr) {
			case 'B': /* For input of B */
				if (state==2) state=3; /* Changes state from 2 to 3 */
				else if (state==3) valid=0; /* Invalid input for state 3 */
				break;
			case 'C': /* For input of C */
				if (state==2) valid=0; /* Invalud input for state 2 */
				else if (state==3) state=2; /* Changes state from 3 to 2 */
				break;
			default: /* Other characters are invalid */
				valid=0;
				break;
			}
		}
	}
}

int check_op() {
	int valid=1; /* 1 for valid message. 0 for invalid */
	int state=2; /* initial state is 2 to follow FSM in guidlines */
	
	/* Print out type char */
	putchar(curr);
	while(1) {
		/* Get the next input */
		curr = getc(input);

		/* If char is EOF or a newline */ 
		if (curr==EOF | curr=='\n') return state==2?valid:0; /* If state is two, return validity, else return INVALID */
		else putchar(curr); /* If not, just print the character */

		/* While the sequence is still considered valid */
		if (valid) {
			/* For given inputs */
			switch (curr) {
			case 'B': /* For input of B */
				if (state==2) state=3; /* Changes state from 2 to 3 */
				else if (state==3) valid=0; /* Invalid input for state 3 */
				break;
			case 'C': /* For input of C */
				if (state==2) valid=0; /* Invalud input for state 2 */
				else if (state==3) state=2; /* Changes state from 3 to 2 */
				break;
			default: /* Other characters are invalid */
				valid=0;
				break;
			}
		}
	}
}

int check_ork() {
	return 0;
}

int main(int argc, char *argv[]) {
	char *fn;

	/* If no arguments are given */
	if (argc == 1) {
		/* FILE pointer is stdin */
		input = stdin;
	}
	/* If one additional argument is given */
	else if (argc == 2) {
		/* Filename is given command linea argument */
		strcpy(fn, argv[1]);
		/* Open file */
		input = fopen(fn, "r");
		/* Error handle file opening */
		if (!input) {
			fprintf(stderr, "ERROR: Failed to open %s file in current directory\n", fn);
			return EXIT_FAILURE;
		}
	}
	/* If more than one additional argument is given */
	else {
		/* Error and print usage */
		fprintf(stderr, "ERROR: Too many arguments\n");
		usage();
		return EXIT_FAILURE;
	}
	
	/* TODO: Handle mutliple lines per input stream */
	/* Get the first character to determine message type */
	switch (curr=getc(input)) {
		case 'E':
			check_foo()?puts(" OK\n"):puts(" FAIL\n");
			break;
		case 'P':
			check_eep()?puts(" OK\n"):puts(" FAIL\n");
			break;
		case 'Q':
			check_op()?puts(" OK\n"):puts(" FAIL\n");
			break;
		case 'M':
			check_ork()?puts(" OK\n"):puts(" FAIL\n");
			break;
	}

	/* If reading from given file */
	if (argc == 2) {
		/* Close the file stream */
		fclose(input);
	}

	return 0;
}
