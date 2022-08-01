#include <stdio.h>

int main() {
	int n, i;

	printf("Enter an integer: ");
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "ERROR: scanf did not match one integer from user input\n");
		return -1;
	}
	while (n>0) {
		for (i=0; i<n; i++){
			printf("*");
		}
		printf("\n");
		n--;
	}
	return 0;
}
