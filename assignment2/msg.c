#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input;
int curr;

void usage() {
	fprintf(stderr, "Usage: ./msg [input filename]\n");
	return;
}

void print_rest() {
	int val;
	while (1) {
		val = getc(input);
		if ( val==EOF | val=='\n' ) {
			return;
		} else {
			putchar(val);
		}
	}
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
		if (curr==EOF | curr=='\n') return state==2?valid:0; /* If state is 2, return validity, else return INVALID */
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
				if (state==2) valid=0; /* Invalid input for state 2 */
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
		if (curr==EOF | curr=='\n') return state==3?valid:0; /* If state is 3, return validity, else return INVALID */
		else putchar(curr); /* If not, just print the character */

		/* While the sequence is still considered valid */
		if (valid) {
			/* For given inputs */
			switch (curr) {
			case '6': /* For input of 6 */
				/* No state change but it is a valid input */
				break;
			case '7': /* For input of 7 */
				if (state==2) state=3; /* Change state from 2 to 3 */
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
	int valid=1; /* 1 for valid message. 0 for invalid */
	int state=0; 
	/* Deviates from FSM numbers: 
	0 means 0 digits entered
	1 means 1 digit entered
	2 means 2 digits entered */
	
	/* Print out type char */
	putchar(curr);
	while(1) {
		/* Get the next input */
		curr = getc(input);

		/* If char is EOF or a newline, only possible way to get here is sequence is not foo or eep */ 
		if (curr==EOF | curr=='\n') return 0;

		/* While the sequence is still considered valid */
		if (valid) {
			switch (state) {
				case 0:
					/* If input is a digit */
					if ( curr>='0' & curr<='9' ) {
						/* Print character and progress states */
						//putchar(curr);
						state=1;
					} else {
						/* Set as invalid if not */
						valid=0;
					}
					break;
				case 1:
					/* If input is a digit */
					if ( curr>='0' & curr<='9' ) {
						/* Print character and progress states */
						state=2;
					} else {
						/* Set as invalid if not */
						valid=0;
					}
					break;
				case 2:
					if ( curr=='E' ) { /* foo specifier */
						return check_foo();	
					} else if ( curr=='P' ) { /* eep specifier */
						return check_eep();
					} else { /* Any other character in state 3 is invalid */
						valid=0;
					}
			}
		}
		if (curr!=EOF & curr!='\n') putchar(curr); /* Print curr if it is not EOF or newline */
	}
}

int main(int argc, char *argv[]) {
	/* If no arguments are given */
	if (argc == 1) {
		/* FILE pointer is stdin */
		input = stdin;
	}
	/* If one additional argument is given */
	else if (argc == 2) {
		/* Open file */
		input = fopen(argv[1], "r");
		/* Error handle file opening */
		if (!input) {
			fprintf(stderr, "ERROR: Failed to open \'%s\' file in current directory\n", argv[1]);
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
	while (curr!=EOF) {
		/* Get the first character to determine message type */
		switch (curr=getc(input)) {
			case 'E': /* foo */
				check_foo()?puts(" OK"):puts(" FAIL");
				break;
			case 'P': /* eep */
				check_eep()?puts(" OK"):puts(" FAIL");
				break;
			case 'Q': /* op */
				check_op()?puts(" OK"):puts(" FAIL");
				break;
			case 'M': /* ork */
				check_ork()?puts(" OK"):puts(" FAIL");
				break;
			case EOF:
				break;
			default:
				/* Print first char */
				putchar(curr);
				/* Print the rest of the string */
				print_rest();
				puts(" FAIL\n");
				break;
		}
	}

	/* If reading from given file */
	if (argc == 2) {
		/* Close the file stream */
		fclose(input);
	}

	return 0;
}
