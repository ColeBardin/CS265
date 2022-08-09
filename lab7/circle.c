#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 64

void usage() {
	printf("Usage: ./circle \"name\" radius\n");
	return;
}

int main(int argc, char *argv[]) {
	char *end;
	double radius;
	char name[STR_MAX];

	if (argc < 3) {
		fprintf(stderr, "ERROR: not enough arguments\nNeeds two arguments, a name and radius\n");
		usage();
		return EXIT_FAILURE;
	} else if (argc > 3) {
		fprintf(stderr, "ERROR: too many arguments\nNeeds two arguments, a name and radius\n");
		usage();
		return EXIT_FAILURE;
	}
	radius = strtod(argv[2], &end);
	
	radius = M_PI*radius*radius;
	printf("%s, your area is %.3E units square\n", argv[1], radius);
	return 0;
}
