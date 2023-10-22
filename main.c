#include "monty.h"

/**
 * main - Entry Point for the program
 * @argc: Command line argument counter
 * @argv: Array of commandline arguments
 * Return: Always 0 or something
 */

int main(int argc, char **argv)
{
	char **all_lines = NULL;

	instruction_t ops_array[] = {
		{"push", op_push},
		{"pop", op_pop},
		{"pall", op_pall},
		{"pint", op_pint},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glob.TOS1 = -99;
	all_lines = read_lines(argv[1]);
	glob.all_lines = all_lines;

	/*LINES NOW IN THE ARRAY*/
	interpreter(ops_array, all_lines);

	return (0);
}
