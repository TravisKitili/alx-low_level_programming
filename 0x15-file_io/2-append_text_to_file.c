#include "main.h"
/**
 *append_text_to_file - adds text at the end of a line
 *@filename: name of the file
 *@text_content: added details
 *Return: 1 if file exists -1 otherwise
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int filedescriptor;
	int x, y;

	if (!filename)
		return (-1);
	filedescriptor = open(filename, O_WRONLY | O_APPEND);
	if (filedescriptor == -1)
		return (-1);
	if (text_content)
	{
		for (x = 0; text_content[x]; x++)
			;
		y = write(filedescriptor, text_content, x);
		if (y == -1)
			return (-1);
	}
	close(filedescriptor);
	return (1);
}
