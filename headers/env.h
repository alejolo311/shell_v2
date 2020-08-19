#ifndef H_ENV
#define H_ENV
#include "libraries.h"

extern char **environ;

/**
 * struct lenv_s - singly linked list
 * @str: variable
 * @next: points to the next node
 * @var: enviroment variables.
 * Description: singly linked list node to store the env
 */
typedef struct lenv_s
{
	char *var;
	struct lenv_s *next;
} lenv_s;


int _env(char **argv, lenv_s **lenv, unsigned int *execnt);
int _setenv(char **argv, lenv_s **lenv, unsigned int *execnt);
int _unsetenv(char **argv, lenv_s **lenv, unsigned int *execnt);
size_t print_list(lenv_s **head);
int delete_node(lenv_s **head, unsigned int index);
char **menv(lenv_s **head);
lenv_s *add_node(lenv_s **head, char *str);
lenv_s *cenv(char **env);
void free_list(lenv_s **head);
char *_getenv(char *name, lenv_s **lenv);
int size_env(int mode, lenv_s **lenv);
void sincro_env(lenv_s **lenv);

#endif /* H_ENV */
