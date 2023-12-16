#include "main.h"
/**
 *get_endianness - checks the endiannesss
 *Return: 0 is endian is big or 1 if its little
 */
int get_endianness(void)
{
	int o;
	char *p;

	o = 1;
	p = (char *)&o;
	return (*p);
}
