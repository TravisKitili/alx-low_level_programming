#include "main.h"
/**
 *get_bit - returns value of bit at given index
 *@n: number
 *@index: index
 *Return: value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int factor, examine;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	factor = 1 << index;
	examine = n & factor;
	if (examine == factor)
		return (1);
	return (0);
}
