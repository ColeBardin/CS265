#include <ctype.h>
#include <string.h>
#include <stdio.h>

/* Capitalizes all lowercase characters in the provided string.
Ignores already capital letters and non-alpha characters.
Edits the string characters in place.
Parameters:
	char *lower: 	String that will be capitalized */
void capitalize(char *lower) {
	/* Length of the string, excluding the NULLCHAR */
	int n = strlen(lower);
	int i;
	char curr;
	/* Iterate through each character of the string */
	for (i=0; i<n; i++) {
		/* Parse current char from index i. *(lower+i) = lower[i] */
		curr = *(lower + i);
		/* Check if the character is an alphabet letter and it is lowercase */
		if ( isalpha(curr) && islower(curr) ) {
			/* If so, capitalize and replace it in the original string */
			*(lower+i) = (char)toupper(curr);
		}
	}
	return;
}

int main() {
	
	char s1[] = "alllower";
	char s2[] = "SoMeLoWeR";
	char s3[] = "Mixed123Chars";

	capitalize(s1); capitalize(s2); capitalize(s3);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	return 0;
}
