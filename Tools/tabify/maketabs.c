#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000000
#define MAXLINE 9999
#define MAXFILENAME 9999

void addTabs(FILE *src, FILE *dst, int spacePerTab){
	char inpDat[MAXLINE];
	char outDat[MAXLINE];

	while(fgets(inpDat, MAXLINE - 1, src)) {
		memset(outDat, '\0', MAXLINE);
		int i = 0;
		int dstChar = 0;
		int count = 0;
		while (inpDat[i] == ' ') {
			count++;
			if (count == spacePerTab) {
				outDat[dstChar] = '\t';
				dstChar++;
			}
			i++;
		}
		strncat(outDat, inpDat, MAXLINE);
		fprintf(dst, "%s", outDat);
	}
}

int main(int argc, char *argv[]){
	
	FILE *inpFile;
	FILE *outFile;
	char inpFilename[MAXFILENAME];
	char outFilename[MAXFILENAME];
	int spacePerTab = 4; // Default value for my editor	

	printf("Tabify, written by Nicholas West\n");

	// Start off with check for actual use
	if (argc == 1) {
		printf("No input, use -h or -H for help\n");
		return 0;
	}
	
	inpFilename[0] = '\0';

	// Get input filename first off
	strncat(inpFilename, *(1 + argv), MAXFILENAME - 1);
	strncpy(outFilename, inpFilename, MAXFILENAME - 1);

	char c;	

	// Loop for every argv and match options
	while (--argc > 0) {
		if ((*++argv)[0] == '-') {		

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
					strncpy(outFilename, *(1 + argv), MAXFILENAME - 1);
					// Because strncpy won't add a \0 if full we add it ourselves
					outFilename[MAXFILENAME - 1] = '\0';
					break;

				default:
					printf("Invalid input, use -h or -H for help\n");
					break;
				}
			}
		}
	}

	// Attempt to open files
	inpFile = fopen(inpFilename, "r");
	if (!inpFile) {
		printf("Could not open %s, does it exist?\n", inpFilename);
		return 1;
	}

	outFile = fopen(outFilename, "w");
	if (!outFile) {
		printf("Could not open output file");
		return 1;
	}

	addTabs(inpFile, outFile, spacePerTab);

	fclose(inpFile);
	fclose(outFile);

	return 0;
}