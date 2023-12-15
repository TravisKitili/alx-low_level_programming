#ifndef MAIN_H
#define MAIN_H
int get_endianness(void);
int _putchar(char c);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
unsigned int binary_to_uint(const char *b);
int clear_bit(unsigned long int *n, unsigned int index);
void print_binary(unsigned long int n);
int set_bit(unsigned long int *n, unsigned int index);
int get_bit(unsigned long int n, unsigned int index);
#endif
