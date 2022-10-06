#include <stdio.h>

#define LIMIT 10000

int main()
{
    short int total = 0;
    short int squared = 0;
    short int i; //the current number in the iteration
    for(i = 0; (squared = ++i * i) < LIMIT;)
    {
        if ((squared % 392) == 0)
        {
            total++;
        }
    }
    printf("%i\n", total);
    return 0;
}