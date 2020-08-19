#ifndef H_HISTORY
#define H_HISTORY

#include "hsh.h"


#define HISTORY_FILE ".simple_shell_history"

/**
 * struct commhist - Structure for the command history
 * @id: Id for the node
 * @cmd: The command
 * @next: The next node
 */
typedef struct commhist
{
	int id;
	char *cmd;
	struct commhist *next;
} commhist_s;

int _history(char **argv, lenv_s **lenv, unsigned int *execnt);
int currhist(commhist_s **h, commhist_s **t);
int addhist(char **argv);
int savehist(lenv_s **lenv);
int sizehist(lenv_s **lenv);
int loadhist(lenv_s **lenv);


#endif /* H_HISTORY */
