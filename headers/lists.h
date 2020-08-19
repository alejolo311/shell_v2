#ifndef H_LISTS
#define H_LISTS
#include "libraries.h"
#include "env.h"


size_t print_list(lenv_s **head);
int delete_node(lenv_s **head, unsigned int index);
lenv_s *add_node(lenv_s **head, char *str);
void free_list(lenv_s **head);

#endif /* H_LISTS */
