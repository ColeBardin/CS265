#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid=0;

int check_foo();
int check_eep();
int check_op();
int check_ork();

void usage() {
	fprintf(stderr, "./msg [input filename]\n");
	return;
}

int main(int argc, char *argv[]) {
	char first;
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

	/* TODO: Open file and error handle */

	/* TODO: Get first char and determine message type */

	/* TODO: Validate message (func prints message too!) */

	/* Close file */
	return 0;
}
