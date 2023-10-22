#include "monty.h"

/**
 * error_not_found - Print Command not found
 * @all_lines:lines array to free
 * @idx:line number
 * @commands: command not found
 */

void error_not_found(char **all_lines, int idx, char *commands)
{
	printf("L%d: unknown instruction %s\n", idx, commands);
	free_arr(all_lines);
	free_stack(&(glob.stack));
	exit(EXIT_FAILURE);
}

/**
 * err_alllines - Prints error and frees all lines
 * @alllines1: Argument to array to free
 * Return: Void
 */
void err_alllines(char **alllines1)
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
 * error_file - Prints error and frees all lines
 * @argv: File name
 * Return: Void
 */

void error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
