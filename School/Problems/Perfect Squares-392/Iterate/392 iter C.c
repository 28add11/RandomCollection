#include <stdio.h>

#define LIMIT 10000

int main()
{
    short int total = 0;
    short int squared;
    short int i = 0; //the current number in the iteration
    while ((++i * i) < LIMIT)
    {
        squared = i * i; //squares i twice, im too dumb to think of a work around TwT
        if ((squared % 392) == 0)
        {
            total++;
        }
    }
    printf("%i\n", total);
    return 0;
}