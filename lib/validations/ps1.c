#include "validations.h"
#include "libraries.h"
#include "env.h"
#include "strings.h"
/**
 * get_ps1 - function enviroment
 * desc: print the enviroment
 * @PS1: the parameters
 * @lenv: the parameters
 * Return: 1 in success.
 */
void get_ps1(char **PS1, lenv_s **lenv)
{
	char *_PS1;

	_PS1 = _getenv("PS1", lenv);
	if (_PS1 == NULL)
		(*PS1) = "($) ";
	else
		(*PS1) = _strdup(_PS1);
}
