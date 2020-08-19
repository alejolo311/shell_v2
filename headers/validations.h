#ifndef H_VALIDATION
#define H_VALIDATION
#include "hsh.h"
/**
 * struct builtin - Structure for builtins
 * @s: String to compare
 * @f: Function to execute
 */
typedef struct builtin
{
	char *s;
	int (*f)();
} builtin_s;
/**
 * struct operator - Structure for operators
 * @s: String to compare
 * @f: Function to execute
 */
typedef struct operator
{
	char *s;
	int (*f)();
} operator_s;

void handsigint(int sign);
int (*check_builtin(char *line))();
int (*check_operator(char *operator))();
int inputfile(int argc, char **argv, lenv_s **lenv, unsigned int *execnt);
char **check_variable(char **argv, lenv_s **lenv);
void get_ps1(char **PS1, lenv_s **lenv);
int validate_multiple_args(int argc, char **argv, lenv_s **env, unsigned int *execnt);

#endif /* H_VALIDATION */
