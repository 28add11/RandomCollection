// A simple program to test the difference in two ways to count the number of items less than x in a given array

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAYLEN 500000000

int *arrayGen() {
    static int randArray[ARRAYLEN];
    for (int i = 0; i < ARRAYLEN; i++) {
        randArray[i] = rand();
    }

    return randArray;
}

int countEach(int *inpArray, int lessThan) {
    int n = 0;
    for (int i = 0; i < ARRAYLEN; i++){
        if (inpArray[i] < lessThan) n++;
    }
    return n;
}

int cmp(const void *a, const void *b) { //qsorting the array for later
    return *(int *)a - *(int *)b;
}

int closeSearch(int *array, int match) { // Since we know the value of numbers less than half the RAND_MAX is going to be near half of ARRAYLEN we can make a well optimized algo for this
    int left = 0;
    int right = ARRAYLEN - 1;
    int result = -1;  // Default value if no such element is found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] > match) {
            result = mid; // Update result and continue searching on the left side
            right = mid - 1;
        } else {
            left = mid + 1; // Continue searching on the right side
        }
    }

    return result;
}

int main(void) {
    srand(time(NULL)); //seeding rand here as to assure randomness with smaller values of LISTLEN, and because its good practice

    printf("Generating list...\n");
    int *randArray = arrayGen();

    printf("Benchmarking counting method...\n");
    int lessThan = (int)(RAND_MAX / 2);
    clock_t start = clock();
    int result1 = countEach(randArray, lessThan);
    clock_t diff = clock() - start;

    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Counting method done. \nResults: \n%i numbers less than %i \nTook %d seconds %d miliseconds \n", result1, lessThan, msec/1000, msec%1000);
    
    printf("Sorting array for method 2/3...\n");
    start = clock();
    qsort(randArray, ARRAYLEN, sizeof(int), cmp);
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;

    printf("Array sorted in %d seconds %d miliseconds. \nBenchmarking method 2.\n", msec/1000, msec%1000);
    start = clock();
    int result2 = closeSearch(randArray, lessThan);
    diff = clock() - start;

    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Method 2 done. \nResults: \n%i numbers less than %i \nTook %d seconds %d miliseconds. \nStarting method 3...\n", result2, lessThan, msec/1000, msec%1000);

    start = clock();
    int result3 = countEach(randArray, lessThan); //now this is the same as method 1, but with branch prediction!
    diff = clock() - start;

    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Method 3 done. \nResults: \n%i numbers less than %i \nTook %d seconds %d miliseconds\n", result3, lessThan, msec/1000, msec%1000);

    return 0;
}