#include<stdio.h>

int bitcount(unsigned x);

int main(void)
{
	unsigned x = 0b010101100; //simple test program
	int btc = bitcount(x);
	short int truth = btc == 4;
	printf("%i\t%i\n", btc, truth);
	return 0;
}

int bitcount(unsigned x)
{
	int b;
	for(b = 0; x != 0; x &= (x - 1))
	{
		b++;
	}
	return b;
}
