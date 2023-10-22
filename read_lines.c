#include "monty.h"

/**
 * read_lines - Reads all lines from file
 * @argv: Name of file from command line
 * Return: An array of all lines
 */

char **read_lines(char *argv)
{
	FILE *fileopen;
	size_t buffsize = 1;
	ssize_t ch_r = 0;
	char **all_lines1 = NULL, *buffer = NULL, *temp;
	int line_num = 0, len = 0;

	fileopen = fopen(argv, "r");
	if (fileopen == NULL)
		error_file(argv);

	while (getline(&buffer, &buffsize, fileopen) != -1)
		len++;
	fclose(fileopen);

	all_lines1 = malloc(sizeof(char *) * (len + 1));
	if (all_lines1 == NULL)
		err_malloc();

	fileopen = fopen(argv, "r");

	while ((ch_r = getline(&buffer, &buffsize, fileopen)) != -1)
	{
		temp = strtok(buffer, "\n");
		if (temp == NULL)
			continue;

		all_lines1[line_num] = _strdup(temp);
		line_num++;
	}
	all_lines1[line_num] = NULL;
	fclose(fileopen);

	if (ch_r == -1)
		free(buffer);

	return (all_lines1);
}
