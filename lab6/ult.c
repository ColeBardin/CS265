#include <stdio.h>

int main() {
	int n, i;

	/* Read int from user */
	printf("Enter an integer: ");
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "ERROR: scanf did not match one integer from user input\n");
		return -1;
	}
	while (n>0) {
		/* Print out n number of * */
		for (i=0; i<n; i++){
			printf("*");
		}
		printf("\n");
		/* Decrement n */
		n--;
	}
	return 0;
}
