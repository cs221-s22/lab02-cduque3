#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	//exit program if more or less than 2 arguments provided
	if( argc != 3 ) {
		printf("2 arguments expected\n", argv[1]);
		return -1;
	}

	//initializing string (haystack) as first argument, substring (needle) as second arguments
	//"count" will increment as an occurence of single character/N-character string is found in a string

	int count = 0;
	char *haystack = argv[1];
	char *needle = argv[2];

	//if a single character is entered, this code is triggered
	if(needle[1] == '\0') {
		for(int it = 0; haystack[it] != '\0'; it++) { //for loop, cycles through each character of string
			if(needle[0] == haystack[it]) {
				count++; //increase count if character in string matches the single character
			}
		}
	}

	//if an N-character is entered, this code is triggered
	else {
		//N and H created to figure out how many iterations there will need to be
		//i.e. subtract the amount of needle's characters from the amount of haystack's characters
		int N = strlen(needle);
		int H = strlen(haystack);
		int j;
		int i;

		for(i = 0; i <= (H-N); i++) { //for loop to iterate the substring through the string
			j = 0;
			while(needle[j] != '\0') { //while loop to iterate through the string and substring's individual characters

				if(needle[j] != haystack[i+j]) { //if-statement to check if each character matches, breaks if one character is off
					break;
				}

				j++;

				if(needle[j] == '\0') { //if this if-statement is reached, means the substring was able to go through the whole string, increase count
					count++;
				}
			}
		}
	}

	//displays amount of character/string matches
	printf("%d instances of %s in %s \n", count, needle, haystack);
}
