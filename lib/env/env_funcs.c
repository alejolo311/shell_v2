#include "env.h"
#include "strings.h"
/**
 * cenv - this function creat a list from env
 * @env: the enviroment
 * Description: this funtion create a list from env
 * section header: the header of this function is hsh.h
 * Return: return the list.
 **/
lenv_s *cenv(char **env)
{
	int i;
	lenv_s *lenv;
	(void) env;

	lenv = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		add_node(&lenv, environ[i]);
	}
	return (lenv);

}
/**
 * menv - this function convert a list to a doble pointer
 * @head: the head of list
 * Description: this converta list to a doble pointer.
 * section header: the header of this function is hsh.h
 * Return: the doble pointer.
 **/
char **menv(lenv_s **head)
{
	int i;
	lenv_s *h = *head;
	char **lenv;

	for (i = 0; h; i++)
		h = h->next;
	lenv = malloc(sizeof(char *) * (i + 1));
	h = *head;
	for (i = 0; h; i++, h = h->next)
		lenv[i] = h->var;
	lenv[i] = NULL;

	return (lenv);
}
/**
 * menv - this function convert a list to a doble pointer
 * @head: the head of list
 * Description: this converta list to a doble pointer.
 * section header: the header of this function is hsh.h
 * Return: the doble pointer.
 **/
int size_env(int mode, lenv_s **lenv)
{
	int i, size = 0;

	if (mode == 1)
	{
	lenv_s *h = *lenv;

	for (i = 0; h ; i++)
	{
		if (h->var == NULL)
			;
		else
		{
			size += _strlen(h->var);
			size += 1;
		}
		h = h->next;
	}	
	}
	else 
	{
	for (i = 0; environ[i] != NULL; i++)
	{
		size += _strlen(environ[i]);
		size += 1;
	}
	}
	return (size);

}
/**
 * menv - this function convert a list to a doble pointer
 * @head: the head of list
 * Description: this converta list to a doble pointer.
 * section header: the header of this function is hsh.h
 * Return: the doble pointer.
 **/
void sincro_env(lenv_s **lenv)
{
	(void) lenv;
}