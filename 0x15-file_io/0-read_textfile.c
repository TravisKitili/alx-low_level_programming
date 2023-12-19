#include "main.h"
/**
 *read_textfile - reads a text file and prints it
 *@filename: name of the file
 *@letters: number of letters
 *Return: number of letters printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedescriptor;
	ssize_t a, b;
	char *workspace;

	if (!filename)
		return (0);
	filedescriptor = open(filename, O_RDONLY);
	if (filedescriptor == -1)
		return (-1);
	workspace = malloc(sizeof(char) * (letters));
	if (!workspace)
		return (0);
	a = read(filedescriptor, workspace, letters);
	b = write(STDOUT_FILENO, workspace, a);
	close(filedescriptor);
	free(workspace);
	return (b);
}
