#include "validations.h"
#include "help.h"
#include "history.h"
#include "cd.h"
#include "exit.h"
#include "strings.h"
#include "operators.h"

/**
 * check_operator - check if the input is a built-in
 * desc: check if the command in the inpit is a valid built-in
 * @builtin: the command to check
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int (*check_operator(char *ope))()
{
	int i; /* the counter to itarate the struct to search the correct builtin" */
	operator_s operator[] = {
		{"&&", logical_and},
		{"||", logical_or},
		{">", redirection},
		{">>", append},
		{"<", to_command},
		{"<<", heredoc},
		{"|", _pipe}
	};
	int operator_len = sizeof(operator) / sizeof(operator_s);
	const char *p = ope;

	if (p != NULL)
	{
		for (i = 0; i < operator_len; i++)
		{
			if (_strcmp(ope, operator[i].s) == 0)
				return (operator[i].f);
		}
	}
	return (NULL);
}
