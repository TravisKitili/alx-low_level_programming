#include "main.h"
/**
 *degree - calculates base to the power
 *@radix: base of exponent
 *@exponent: power
 *Return: value of base to the power
 */
unsigned long int degree(unsigned int radix, unsigned int exponent)
{
	unsigned long int x;
	unsigned int y;

	x = 1;
	for (y = 1; y <= exponent; y++)
		x *= radix;
	return (x);
}
/**
 *print_binary - outputs in binary notation
 *@n: number
 *Return: ---
 */
void print_binary(unsigned long int n)
{
	unsigned long int factor, inspect;
	char indicator;

	indicator = 0;
	factor = degree(2, sizeof(unsigned long int) * 8 - 1);
	while (factor != 0)
	{
		inspect = n & factor;
		if (inspect == factor)
		{
			indicator = 1;
			_putchar('1');
		}
		else if (indicator == 1 || factor == 1)
		{
			_putchar('0');
		}
		factor >>= 1;
	}
}
