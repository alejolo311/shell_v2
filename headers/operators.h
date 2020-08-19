#ifndef H_OPERATORS
#define H_OPERATORS
#define READ_END 0
#define WRITE_END 1
#include "hsh.h"

int logical_and(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
int logical_or(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
int redirection(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
int append(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
int to_command(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
int heredoc(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
int _pipe(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);

#endif /* H_OPERATORS */
