#include "env.h"
#include "strings.h"
#include "operators.h"
/**
 * redirection - function enviroment
 * desc: print the enviroment
 * @argc: the parameters
 * @argv: the parameters
 * @lenv: the enviroment list
 * @execnt: the counter
 * Return: 1 in success.
 */
int redirection(int argc, char **argv, lenv_s **lenv, unsigned int *execnt)
{
	printf("function to manage the > operator\n");
	(void) lenv;
	(void) argv;
	(void) execnt;
	return (EXIT_SUCCESS);
}
