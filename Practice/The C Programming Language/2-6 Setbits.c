#include <stdio.h>
    
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x = 0b01100101; //simple test program for demo reasons
    unsigned y = 0b10101010;
    unsigned bitset = setbits(x, 7, 4, y);
    int truth = bitset == 0b10100101;
    printf("%x\n%i\n", bitset, truth);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned ybitget = (y & ~(~0 << n)) << p + 1 - n; //both of these do the same thing in the end, just in different orders. First, a mask is created with the width of n
    unsigned xbitget = x & ~(~(~0 << n) << p + 1 - n);//then, this mask is shifted to the position required, at which point it is applied. In ybitget's case, the mask is
    //applied before the position shifting, as to meet the question requirements.
    return xbitget | ybitget;
}