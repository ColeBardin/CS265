#include <stdio.h>
#include <stdlib.h>

int main(){
	double total, sub, tax, tip = 0;
	
	printf("Enter bill amount: $");
	if (scanf("%lf", &total) != 1) {
		fprintf(stderr, "ERROR: scanf did not match one double for the total\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter your subtotal amount: $");
	if (scanf("%lf", &sub) != 1) {
		fprintf(stderr, "ERROR: scanf did not match one double for subtotal\n");
		return EXIT_FAILURE;
	}

	if ( total < sub ) {
		fprintf(stderr, "ERROR: subtotal amount is greater than the bill\n");
		return EXIT_FAILURE;
	}

	tax=0.07*sub;
	tip=0.22*sub;

	printf("Of the $%.2lf bill, the user is responsible for:\nItem subtotal: $%.2lf\n7 Percent Tax: $%.2lf\n22 Percent Tip: %.2lf\nUser total: %.2lf\n", total, sub, tax, tip, sub+tip+tax);
	return 0;
}
