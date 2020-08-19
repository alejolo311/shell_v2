#include "hsh.h"
#include "history.h"
#include "validations.h"
#include "strings.h"

char **askmem(int argc, char *line);

/**
 * interact - Exececutes a command
 * @av: Parameters for the program
 * @lenv: The variables from the environment list
 * @execnt: the counter
 * Return: Always 0
 */
int interact(char **av, lenv_s **lenv, unsigned int *execnt)
{
	size_t len = 0;
	int read = 1, j, argc = 0, inter = 1, (*f)() = NULL;
	int builtin, ret = 0, mul = 0;
	char *str1, *t, **argv, *line = NULL;
	char *tmp = NULL, *myline = NULL, *PS1 = NULL;

	isatty(STDIN_FILENO) == 0 ? inter = 0 : inter;
	get_ps1(&PS1, lenv);

	do {
		inter == 1 ?  write(STDOUT_FILENO, PS1, _strlen(PS1)) : inter;
		fflush(stdin);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{	read == -1 && inter == 1 ? write(1, "\n", 1) : read;
			free(line);
			return (ret);
		}
		myline = _strdup(line);
		tmp = _strdup(myline);
		argc = 1;
		str1 = tmp;
		for (; (t = strtok(str1, " \t\n")); argc++, str1 = NULL)
			if (t == NULL)
				break;
		argv = askmem(++argc + 2, myline);
		if (argv == NULL)
			return (-1);
		argv[0] = av[0];
		for (j = 1, str1 = myline; ; j++, str1 = NULL)
		{	t = strtok(str1, " \t\n"), argv[j] = t;
			if (t == NULL)
				break;
		}
		mul = validate_multiple_args(argc, argv, lenv, execnt);
		if (mul != 0)
			continue;
		f = check_builtin(myline);
		if (f != NULL)
		{	builtin = f(argv, lenv, execnt);
			if (_strncmp(myline, "exit", 4) == 0 && builtin >= 0)
			{	free(tmp), free(myline), free(line);
				if (argv[2] != NULL)
				{
					free(argv);
					return (builtin);
				}
				free(argv);
				return (ret);
			}
			ret = builtin;
		}
		else
			argc > 2 ? ret = myexec(j, argv, lenv, execnt) : argc;
		addhist(argv), free(argv), free(tmp), free(myline), (*execnt)++;
		if ((ret == 127 || ret == 126 || ret == 2) && inter == 0)
		{	free(line);
			return (ret);
		}
	} while (1);
	free(myline), free(line), free(PS1);
	return (ret);
}

/**
 * askmem - Allocates memory
 * @argc: Amount of memory to allocate
 * @myline: The pointer to line readed
 * Return: A pointer to the new memory area or NULL
 */
char **askmem(int argc, char *myline)
{
	char **argv;

	argv = malloc((argc) * sizeof(char **));
	if (argv == NULL)
	{
		free(myline);
		perror("Error: ");
		return (NULL);
	}
	return (argv);
}
