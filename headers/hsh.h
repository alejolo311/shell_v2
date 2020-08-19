#ifndef H_SHELL
#define H_SHELL

#include "env.h"

int myexec(int argc, char **argv, lenv_s **env, unsigned int *execnt);
int interact(char **argv, lenv_s **env, unsigned int *execnt);
char *path(char *name, lenv_s **env);

#endif /* H_SHELL */
