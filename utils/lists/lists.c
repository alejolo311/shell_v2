#include "lists.h"
#include "strings.h"
/**
 * add_node - add a new node to a list
 * a blank line
 * @head: the head of list
 * @str: the string to put in the new node
 * Description: add a new node to a list
 * section header: the header of this function is hsh.h
 * Return: the head of the list.
 */
lenv_s *add_node(lenv_s **head, char *str)
{
	lenv_s *node, *tail;
	char *_str;

	tail = *head;

	if (str == NULL)
		return (NULL);
	node = malloc(sizeof(lenv_s));
	if (node == NULL)
		return (NULL);
	_str = _strdup(str);
	if (_str == NULL)
	{
		free(node);
		return (NULL);
	}
	node->var = _str;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	while (tail->next)
		tail = tail->next;

	tail->next = node;

	return (tail);

}
/**
 * print_list - this function prints a list
 * @head: the head of list
 * Description: this function prints a list
 * section header: the header of this function is hsh.h
 * Return: the number of nodes
 **/
size_t print_list(lenv_s **head)
{
	int i;

	lenv_s *h = *head;

	for (i = 0; h ; i++)
	{
		if (h->var == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->var);
		h = h->next;
	}

	return (i);
}
/**
 * free_list - free a list
 * @head: the head of list
 * Description: this function free a list.)?
 * section header: the header of this function is lists.h)*
 * Return: void, no return
 **/
void free_list(lenv_s **head)
{
	lenv_s *h;
	lenv_s *position, *next;


	h = *head;
	position = h;
	while (position != NULL)
	{
		next = position->next;
		free(position->var);
		free(position);
		position = next;
	}
	h = '\0';
}
/**
 * delete_node - thsi function delete a node
 * @head: the head of list
 * @index: the index to put the delete node
 * Description: this function delete a node
 * section header: the header of this function is hsh.h
 * Return: 1 in success -1 in failure
 **/
int delete_node(lenv_s **head, unsigned int index)
{
	lenv_s *actual, *next;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	actual = *head;

	if (index == '\0')
	{
		*head = actual->next;
		free(actual);
		return (1);
	}

	for (i = 0; actual && i < index - 1; i++)
		actual = actual->next;

	if (actual == NULL || actual->next == NULL)
		return (-1);

	next = actual->next->next;
	free(actual->next->var);
	free(actual->next);
	actual->next = next;
	return (1);
}