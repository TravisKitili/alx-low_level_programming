#include "main.h"
#include <stdlib.h>
/**
 *clear_bit - sets value of a bit to 0
 *@n: input
 *@index: offset
 *Return: 1 for success otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
