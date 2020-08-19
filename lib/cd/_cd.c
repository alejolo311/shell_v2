#include "hsh.h"
#include "strings.h"
#include "cd.h"
/**
 * _cd - function cd
 * desc: change between directories
 * @argv: the parameters
 * @e : the executions counter
 * @lenv: the enviroment list
 * Return: EXIT_SUCCESS in success.
 */
int _cd(char **argv, lenv_s **lenv, unsigned int *e)
{	char ynprn = 0, *home = NULL, *pwd = NULL, *PR = NULL, *new = NULL, *av[4];
	unsigned int size = 512;

	home = _getenv("HOME", lenv), pwd = _getenv("OLDPWD", lenv);
	if (home != NULL && chdir(home) == -1)
	{	prnerr(argv[0], e, home), free(home), free(pwd), free(PR);
		return (-1);
	}
	if (askcwd(&PR, size) == -1)
	{	home != NULL ? free(home) : 1, free(pwd);
		return (-1);
	}
	if (argv[2] == NULL && home != NULL)
		return (-1);
	else if (home != NULL &&  argv[2] != NULL && argv[2][0] == '~')
		return (-1);
	else if (argv[2] != NULL && argv[2][0] == '-')
		ynprn = 1;
	else
	{
		if (argv[2] != NULL && argv[2][0] != '-' && argv[2][0] != '~')
		{
			if (chdir(argv[2]) == -1)
			{	home != NULL ? free(home) : 1;
				prnerr(argv[0], e, argv[2]), free(pwd), free(PR);
				return (-1);
			}
		}
	}
	if (askcwd(&new, size) == -1)
	{	home != NULL ? free(home) : 1;
		free(pwd), free(PR);
		return (-1);
	}	av[0] = "./hsh", av[1] = "cd", av[2] = "OLDPWD", av[3] = PR;
	_setenv(av, lenv, e);
	av[0] = "./hsh", av[1] = "cd", av[2] = "PWD", av[3] = new;
	_setenv(av, lenv, e);
	if (ynprn)
		write(STDOUT_FILENO, new, _strlen(new)), write(STDOUT_FILENO, "\n", 1);
	free(PR), free(new);
	return (EXIT_SUCCESS);
}
/**
 * askcwd - Get the current path
 * @path: the variable to store de value
 * @size: the lenght of bytes for the variable
 * Return: EXIT_SUCCESS when success, -1 if fails.
 */
int askcwd(char **path, unsigned int size)
{
	if (*path != NULL)
		free(path);
	*path = malloc(size);
	if (*path == NULL)
		return (-1);
	while (getcwd(*path, size) == NULL)
	{
		size += 64;
		free(path);
		*path = malloc(size);
		if (*path == NULL)
			return (-1);
	}
	return (EXIT_SUCCESS);
}

/**
 * prnerr - Prints the errors on stdout
 * @prg: the name of shell
 * @e: the execution counter
 * @path: the path that fails
 * Return: Nothing.
 */
void prnerr(char *prg, unsigned int *e, char *path)
{
char msg[80];

	sprintf(msg, "%s: %d: cd: can't cd to %s\n", prg, *e, path);
	write(STDERR_FILENO, msg, _strlen(msg));
}
