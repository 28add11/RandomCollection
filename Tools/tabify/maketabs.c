#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 1000000
#define MAXFILENAME 9999

int main(int argc, char *argv[]){
	
	FILE *inpFile;
	int spacePerTab = 4; // Default value for my editor
	char filename[MAXFILENAME];

	char c;

	for (int i = 0; i < argc; i++) {
		printf("%s%s", argv[i], "\n");
	}
	

	printf("Tabify, written by Nicholas West\n");
	// Loop for every argv and match options
	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0]) {
			switch (c) {
			case 'h': case 'H': // Help case
				printf("Tabify: Turns a file with spaces as indentation into tabs.\nUse -n to define the number of spaces ");
				printf("in a tab, and add the name of the file to convert at the end\n");
				break;

			case 'n':
				printf("%s\n", *(1 + argv));
				spacePerTab = atoi(*++argv);
				printf("%i\n", spacePerTab);
				break;
			
			default:
				printf("%s\n", *argv);
				printf("Use -h or -H for help\n");
				break;
			}
		}
		
	}
	
	printf("%i\n", spacePerTab);

	return 0;
}