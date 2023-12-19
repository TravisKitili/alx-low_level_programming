#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *make_buf(char *record);
void shut_record(int filedesc);
/**
 *make_buf - allocates bytes for a buffer
 *@record: name of file
 *@Return: pointer
 */
char *make_buf(char *record)
{
	char *workspace;

	workspace = malloc(sizeof(char) * 1024);
	if (workspace == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n",record);
		exit(99);
	}
	return (workspace);
}
/**
 *shut_record - closes file descriptors
 *@filedesc: file descriptor
 */
void shut_record(int filedesc)
{
	int o;

	o = close(filedesc);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filedesc);
		exit(100);
	}
}
/**
 *main - entry point
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 success
 */
int main(int argc, char *argv[])
{
	int incoming, outgoing, a, b;
	char *reserve;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	reserve = make_buf(argv[2]);
	incoming = open(argv[1], O_RDONLY);
	a = read(incoming, reserve, 1024);
	outgoing = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (incoming == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n",
					argv[1]);
			free(reserve);
			exit(98);
		}
		b = write(outgoing, reserve, a);
		if (outgoing == -1 || b == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
					argv[2]);
			free(reserve);
			exit(99);
		}
		a = read(incoming, reserve, 1024);
		outgoing = open(argv[2], O_WRONLY | O_APPEND);
	}while (a > 0);
	free(reserve);
	shut_record(incoming);
	shut_record(outgoing);
	return (0);
}
