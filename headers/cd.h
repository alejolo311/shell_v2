#ifndef H_CD
#define H_CD

#include "env.h"

int _cd(char **argv, lenv_s **lenv, unsigned int *execnt);
int askcwd(char **path, unsigned int size);
void prnerr(char *prg, unsigned int *e, char *path);

#endif /* H_CD */
