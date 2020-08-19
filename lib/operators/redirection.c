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
	char **first, *operator, *second;
	int fd, _write, i, stdout_cpy;

	(void) lenv;
	(void) argv;
	(void) execnt;

	first = malloc(3 * sizeof(char **));
	if (!first)
		return (-1);
	first[0] = argv[0];
	first[1] = argv[1];
	second = argv[3];

	fd = open(second, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	stdout_cpy = dup(1);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		return (EXIT_FAILURE);
	}

	myexec(1, first, lenv, execnt);
	fflush(stdout);
	if (dup2(stdout_cpy, 1) == -1)
	{
		perror("dup2");
		return (EXIT_FAILURE);
	}


	close(fd);
	return (1);
}
