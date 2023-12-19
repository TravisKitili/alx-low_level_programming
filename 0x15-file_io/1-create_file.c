#include "main.h"
/**
 *create_file - generates a file
 *@filename: name of the file
 *@text_content: content of the file
 *Return: 1 on succss -1 otherwise
 */
int create_file(const char *filename, char *text_content)
{
	int filedescriptor;
	int x, z;

	if (!filename)
		return (-1);
	filedescriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (filedescriptor == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	for (x = 0; text_content[x]; x++)
		;
	z = write(filedescriptor, text_content, x);
	if (z == -1)
		return (-1);
	close(filedescriptor);
	return (1);
}
