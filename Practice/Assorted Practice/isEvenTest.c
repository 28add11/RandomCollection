// I was inspired by the NPM package "is-odd" to make this
// I want to test if my method is faster than theirs
// Fuck javascript

// CONCLUSION:
// Because compilers optimize both methods are equally fast, sans minor variations caused by god knows what
// I still hate javascipt though, but compilers are cool

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAYLEN 500000000

int *randGen(void) {
	static int randArray[ARRAYLEN];
	for (int i = 0; i < ARRAYLEN; i++) {
		randArray[i] = rand();
	}

	return randArray;
}


int moduloTest(int *array) { // Test how many odd nums there are with modulo ("is-odd" method)
	int sum = 0;
	for (int i = 0; i < ARRAYLEN; i++) {
		if (!(array[i] % 2)) sum++; // ! binds tighter than % so brackets are necessary
	}
	return sum;
}

int bitandTest(int *array) { // Test by AND-ing the last bit (2^0 = 1) since if it is set it will be odd
	int sum = 0;             // Should be faster without compiler optimizations since no division is involved
	for (int i = 0; i < ARRAYLEN; i++) {
		if (!(array[i] & 0x01)) sum++;
	}
	return sum;
}


int main(void) {
	srand(time(NULL)); // Seeding rand
	int *mainArray = randGen();

	clock_t start = clock();
	int result = moduloTest(mainArray);
	clock_t diff = clock() - start;

	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Modulo Method done. \nResults: \n%i odd numbers \nTook %d seconds %d miliseconds \n", result, msec/1000, msec%1000);

	start = clock();
	result = bitandTest(mainArray);
	diff = clock() - start;

	msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("BitAnd Method done. \nResults: \n%i odd numbers \nTook %d seconds %d miliseconds \n", result, msec/1000, msec%1000);

	return 0;
}