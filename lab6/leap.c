#include <stdio.h>
#include <stdlib.h>

int main() {
	int year;
	printf("Enter a year: ");
	if (scanf("%d", &year) != 1) {
		printf("ERROR: scanf call did not match one integer");
		return EXIT_FAILURE;
	}
	/* Logic Tree:
	Is Year divisible by 4?
		No: print NO
		Yes: Is Year divisible by 100?
			No: print YES
			Yes: Is Year divisible by 400?
				No: print NO
				yes: print YES */
	year%4?puts("NO"):year%100?puts("YES"):year%400?puts("NO"):puts("YES");

	return 0;
}
