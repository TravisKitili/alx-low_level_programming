#include "main.h"
/**
 *flip_bits - returns number of bits needed to flip
 *@n: first integer
 *@m: second integer
 *Return: number of bits needed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, bitsetcount = 0;
	unsigned long int active;
	unsigned long int distinct = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		active = distinct >> x;
		if (active & 1)
			bitsetcount++;
	}
	return (bitsetcount);
}
