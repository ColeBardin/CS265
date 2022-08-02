#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr;

void usage() {
	fprintf(stderr, "Usage: ./msg [input filename]\n");
	return;
}

int check_foo() 
int check_eep();
int check_op();
int check_ork();

int main(int argc, char *argv[]) {
	int first;
	char *fn;
	FILE *input;

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
	
	/* Get the first character to determine message type */
	switch (getc(input)) {
		case 'E':
			check_foo()?puts(" OK"):puts(" FAIL");
			break;
		case 'P':
			check_eep()?puts(" OK"):puts(" FAIL");
			break;
		case 'Q':
			check_op()?puts(" OK"):puts(" FAIL");
			break;
		case 'M':
			check_ork()?puts(" OK"):puts(" FAIL");
			break;
	}

	/* If reading from given file */
	if (argc == 2) {
		/* Close the file stream */
		fclose(input);
	}

	return 0;
}
