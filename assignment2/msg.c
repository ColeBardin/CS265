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
	int valid=1;
	int state=2;
	putchar('E');
	while(1) {
		curr = getc(input);
		if (curr==EOF | curr=='\n') {
			if (valid) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			putchar(curr);
		}

		if (valid) {
			switch (curr) {
			case '0':
				if (state==2) state=3;
				else if (state==3) state=3;
				else if (state==4) valid=0;
				break;
			case '1':
				if (state==2) state=3;
				else if (state==3) state=3;
				else if (state==4) valid=0;
				break;
			case '2':
				if (state==2) state=3;
				else if (state==3) state=3;
				else if (state==4) valid=0;
				break;
			case 'F':
				if (state==2) valid=0;
				else if (state==3) state=4;
				else if (state==4) valid=0;
				break;
			}
		}
	}
}

int check_eep() {
	return 0;
}

int check_op() {
	return 0;
}

int check_ork() {
	return 0;
}

int main(int argc, char *argv[]) {
	int first;
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
	switch (getc(input)) {
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
