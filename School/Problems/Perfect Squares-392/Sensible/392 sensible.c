#include <stdio.h>

#define LIMIT 10000
#define BASESQ 784 //magic # time! this one is just the smallest perfect square divisible by 392

int main()
{
    short int total = 0;
    short int i = 1; //the current number in the iteration
    for(i = 0; (BASESQ * (++i * i)) < LIMIT;)
    {
        total++;
    }
    printf("%i\n", total);
    return 0;
}