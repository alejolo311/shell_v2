#include "env.h"
#include "strings.h"
/**
 * _unsetenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @lenv: the enviroment
 * Return: 1 in success.
 */
int _unsetenv(char **argv, lenv_s **lenv, unsigned int *execnt)
{
	unsigned int i;
	lenv_s *h;
	char *var;

	(void)execnt;
	h = *lenv;
	if (argv[2] && argv[3] == NULL)
	{
		for (i = 0; h; i++)
		{
			var = h->var;
			if (_strncmp(var, argv[2], _strlen(argv[2])) == 0)
			{
				delete_node(lenv, i);
				break;
			}
			else
			{
				h = h->next;
			}
		}
	}
	return (1);
}
