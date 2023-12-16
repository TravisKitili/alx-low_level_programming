#include "main.h"
/**
 *set_bit - sets value to 1
 *@n: number
 *@index: index
 *Return: 1 for success, otherwise -1 for error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int toggle;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	toggle = 1 << index;
	*n = *n | toggle;
	return (1);
}
