#include "monty.h"

/**
 * ERROR_NOT_FOUND - print command not found
 * @all_lines:lines array to free
 * @idx:line number
 * @commands: command not found
 */

void ERROR_NOT_FOUND(char **all_lines, int idx, char *commands)
	{
	printf("L%d: unknown instruction %s\n", idx, commands);
	free_arr(all_lines);
	free_stack(&(glob.stack));
	exit(EXIT_FAILURE);
}

/**
 * ERROR_ALLLINES - prints error and frees all lines
 * @ALLLINES1: Argument to array to free
 * Return: void
 */
void ERROR_ALLLINES(char **ALLLINES1)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arr(alllines1);
	exit(EXIT_FAILURE);
}

/**
 * err_malloc - Prints malloc error alone
 * Return: Void
 */
void err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * ERROR_FILE - prints error and frees all lines
 * @argv: File name
 * Return: void
 */

void ERROR_FILE(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
