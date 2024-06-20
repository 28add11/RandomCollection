#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARRAY 1000000
#define MAXFILENAME 9999

int main(int argc, char *argv[]){
	
	FILE *inpFile;
	FILE *outFile;
	char inpFilename[MAXFILENAME];
	char outFilename[MAXFILENAME];
	int spacePerTab = 4; // Default value for my editor

	outFilename[0] = '\0';

	char c;	

	printf("Tabify, written by Nicholas West\n");

	// Start off with check for actual use
	if (argc == 1) {
		printf("No input, use -h or -H for help\n");
		return 0;
	}
	
	// Get input filename first off
	strncat(inpFilename, *(1 + argv), MAXFILENAME - 1);

	// Loop for every argv and match options
	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0]) {
			switch (c) {
			case 'h': case 'H': // Help case
				printf("Tabify: Turns a file with spaces as indentation into tabs.\n");
				printf("Usage: ./tabify [input file] -o [output file]\nThe first argument is always the input file\n");
				printf("Arguments:\n-n: Number of spaces in 1 indent\n-o: The name of the file to output, input file will be ");
				printf("erased if not used\n");
				break;

			case 'n':
				// We use *(1 + argv) rather than *++argv because c would be assigned to num rather than char
				spacePerTab = atoi(*(1 + argv));
				break;

			case 'o':
				strncat(outFilename, *(1 + argv), MAXFILENAME - 1);
				break;
			
			default:
				printf("Invalid input, use -h or -H for help\n");
				break;
			}
		}
		
	}

	printf("%s\t%s\t%i\n", inpFilename, outFilename, spacePerTab);

	return 0;
}