#include <stdio.h>

int main() {
	int n, i, s;

	/* Read int from user */
	printf("Enter an integer: ");
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "ERROR: scanf did not match one integer from user input\n");
		return -1;
	}
	/* Set counter for spaces */
	s=n;
	while (n>0) {
		/* Print out a space for the difference between space numbers and n */
		for (i=0; i<s-n; i++){
			printf(" ");
		}
		/* Print out n * */
		for (i=0; i<n; i++){
			printf("*");
		}
		printf("\n");
		/* Decrement n */
		n--;
	}
	return 0;
}
