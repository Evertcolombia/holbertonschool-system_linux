#ifndef _LS_H_
#define _LS_H_

/* module imports */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
/* ---------------- */


/**
 * struct ls_node  - our struct
 *
 * @name: name of the file / dir
 * @next: ponter to next node
 *
 */
typedef struct ls_node
{
	char *name;
	struct ls_node *next;
} ls_n;


/**
 * struct ls_control  - linked list controller
 *
 * @size: size of l list
 * @match: pointer to function
 * @destroy: pointer to func
 * @head: ehad of l list
 * @last_in: last node inserted
 * @tail: tail of list
 */

typedef struct ls_control
{
	int size;

	ls_n *head;
	ls_n *tail;
	ls_n *last_in;
} ls_c;

/* prototypes and macros to  control a linked list */
void list_init(ls_c *list);
void list_destroy(ls_c *list);
int list_ins_next(ls_c *list, ls_n *element, const void *name);
int list_rem_next(ls_c *list, ls_n *element, void **name);
void print_list_safe(ls_c *list, ls_n *head);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, el) ((el) == (list)->head ? 1 : 0)
#define list_is_tail(el) ((el)->next == NULL ? 1 : 0)
#define list_name(el) ((el)->name)
#define list_next(el) ((el)->next)
/* ----------------------------------------------- */

/* core and core_helpers rototypes */
void create_dir_list(const char *path, int ac);
int statinfo(const char *pathname, char *name, ls_c *list, bool isFree);
DIR *open_directory(DIR *dirp, char *path);
void print_safe(int ac, ls_c *list, char *copy);
int dont_get_flags(char *name, char *path, ls_c *list);
int pass_hidden(char *name);
/* ------------------------------- */

/* other prototypes */
int print_list(int size, ls_n *head);
void error_mannager(int errid, bool isDir, char *path);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
/* ---------------- */

/* buffer core helpers prototypes */
char *allocBuf(char *dest, char *path, char *name, char *com);
char *path_controller(char *path, char *name);
/* ------------------------------ */


#endif /* _LS_H_ */
