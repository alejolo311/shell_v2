#include "hsh.h"
#include "strings.h"

/**
 * path - Evaluate the name for execution taking into account PATH if necessary
 * @name: Name of the command to execute
 * @lenv: The environment list
 * Return: For succesful the full path other case NULL.
 */
char *path(char *name, lenv_s **lenv)
{
	unsigned int i;
	int j, k;
	char *s1, *token, *tmp = NULL, **env = menv(lenv);
	static char **ps, *pa;

	if (_strncmp(name, "FLUSH", 5) == 0)
	{	free(pa), free(ps), free(env);
		return (NULL);
	}
	if (access(name, F_OK | R_OK | X_OK) == 0 &&
		(name[0] == '/' || name[0] == '.'))
	{	free(env);
		return (_strdup(name));
	}
	if (ps == NULL)
	{
		for (i = 0; env[i] != NULL; i++)
			if (_strncmp(env[i], "PATH", 4) == 0)
				break;
		if (env[i] == NULL)
		{	free(env);
			return (NULL);
		} tmp = _strdup(env[i]);
		for (k = 1, s1 = tmp; (token = strtok(s1, ":")); k++, s1 = NULL)
			if (token == NULL)
				break;
		free(tmp), pa = _strdup(env[i]), ps = malloc(k * sizeof(char **));
		for (j = 0, s1 = (pa + 5); ; j++, s1 = NULL)
		{	ps[j] = strtok(s1, ":");
			if (ps[j] == NULL)
				break;	}
	} for (k = 0; ps[k] != NULL; k++)
	{	tmp = malloc((_strlen(ps[k]) + _strlen(name) + 2));
		sprintf(tmp, "%s/%s", ps[k], name);
		if (access(tmp, F_OK | R_OK | X_OK) == 0)
		{	free(env);
			return (tmp);
		} free(tmp);
	} free(env);
	return (NULL);
}
