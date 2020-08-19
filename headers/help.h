#ifndef H_HELP
#define H_HELP

#include "hsh.h"

int _help(char **argv, lenv_s **lenv, unsigned int *execnt);
int _hlphelp(char **av, lenv_s **lenv, unsigned int *e);
int _hlpcd(char **av, lenv_s **lenv, unsigned int *e);
int _hlpexit(char **av, lenv_s **lenv, unsigned int *e);
int _hlphistory(char **av, lenv_s **lenv, unsigned int *e);
int prn_help(char *command);
int prn_hlpcd(void);
int prn_hlpexit(void);
int prn_hlphelp(void);
int prn_hlphistory(void);


#endif /* H_HELP */
