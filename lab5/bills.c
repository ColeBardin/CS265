#include <stdio.h>
#include <stdlib.h>

int main(){
	int d;

	printf("Enter a dollar amount => $");
	if(scanf("%d", &d) != 1){
		fprintf(stderr, "ERROR: scanf call did not match 1 integer\n");
		return EXIT_FAILURE;
	}
	printf("$20 bills: %4d\n", d/20);
	d=d%20;
	printf("$10 bills: %4d\n", d/10);
	d=d%10;
	printf("$ 5 bills: %4d\n", d/5);
	d=d%5;
	printf("$ 1 bills: %4d\n", d);

	return 0;
}
