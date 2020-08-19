#include "validations.h"
#include "hsh.h"
#include "env.h"
#include "strings.h"
/**
 * validate_multiple_args - function enviroment
 * desc: print the enviroment
 * @argc: the parameters
 * @argv: the parameters
 * @env: the enviroment list
 * @execnt: the counter
 * Return: 1 in success.
 */
int validate_multiple_args(int argc, char **argv, lenv_s **env,
							unsigned int *execnt)
{

	int i = 0, (*ope)() = NULL, ret = 0;

	for (i = 0; i < argc; i++)
	{
		ope = check_operator(argv[i]);
		if (ope != NULL)
			ret = ope(argc, argv, env, execnt);
	}
	return (ret);
}
