#include "main.h"
#include <stdio.h>
/**
 *check_doc - checks if files can be opened
 *@source: file
 *@destination: file
 *@argv: argument vector
 *Return: ---
 */
void check_doc(int source, int destination, char *argv[])
{
	if (source == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				argv[1]);
		exit(98);
	}
	if (destination == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				argv[2]);
		exit(99);
	}
}
/**
 *main: entry point
 *@argc: argument count
 *@argv: argument vector
 *return: 0 success
 */
int main(int argc, char *argv[])
{
	int source, destination, seal_error;
	ssize_t i, j;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp source destination");
		exit(97);
	}
	source = open(argv[1], O_RDONLY);
	destination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND,
			0664);
	check_doc(source, destination, argv);
	i = 1024;
	while (i == 1024)
	{
		i = read(source, buffer, 1024);
		if (i == -1)
			check_doc(-1, 0, argv);
		j = write(destination, buffer, i);
		if (j == -1)
			check_doc(0, -1, argv);
	}
	seal_error = close(source);
	if (seal_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source);
		exit(100);
	}
	seal_error = close(destination);
	if (seal_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source);
		exit(100);
	}
	return (0);
}
