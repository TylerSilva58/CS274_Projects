/* Challenge 2.5 Determine Character Types */
/* Tyler Silva */

#include <stdio.h>
#include <ctype.h>


int checker (char str[]) { 

	int cap_count = 0; 
	int low_count = 0;
	int alp_count = 0; 
	int num_count = 0; 
	int pun_count = 0; 

	for (int i = 0; str[i] != '\0'; i++) { 
		if (isupper(str[i])) {
			cap_count++;
		}
		if (islower(str[i])) {
			low_count++;
		}
		if (isalpha(str[i])) {
			alp_count++;
		}
		if (isdigit(str[i])) {
			num_count++;
		}			
		if (ispunct(str[i])) {
			pun_count++;
		}
	}
	printf("Capitals: %d\n", cap_count); 
	printf("Lowercase: %d\n", low_count); 
	printf("Alphabet: %d\n", alp_count); 
	printf("Numeric: %d\n", num_count); 
	printf("Punctuation: %d\n", pun_count); 
	return 0;
}

int main (int argc, char *argv[]) { 

	checker(argv[1]); 

}