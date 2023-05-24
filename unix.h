#ifndef _UNIX_H
#define _UNIX_H


/**
 * struct builtin_s - new struct type defining builtin commands
 * @name: name of builtin command
 * @f: function pointer to the builtin commands
 */


typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;


/* Builtins */

int (*get_builtin(char *command))(char **args, char **front);


#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>


typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t; 


/* Global environment */
extern char **environ;
/* Global program name */
int hist;

/* Main Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_itoa(int num);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_path_dir(char *path);
list_t *get_path_dir(char *path);
int execute(char **args, char **front);
void free_list(list_t *head);


/* Input Helpers */
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
char ** replace_aliases(char **args);
void free_args(char **args, cahr **front);
int check_args(char **args);
int handle_args(int *exe_ret); 

/* Strings functions */
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *strchr(char *s, char c);
int strspn(char *s, char *accept);

/* Builtins */
int (*get_builtin(char *command))(char **args, char **front);
int shellby_help(char **args, char _attribute_((_unused_)) **front);
int shellby_exit(char **args, char **front);
int shellby_alias(char **args, char_attribute_((_unused_)) **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);

/* Builtin Helpers */
void free_env(void);
char **_getenv(const char *var);
char **_copyenv(void);

/* this handles error */
char *error_127(char **args);
int create_error(char **args, int err);
char *error_env(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_1(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);


/* this are Linkedlist Helpers */
void free_list(list_t *head);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);

void help_cd(void);
void help_all(void);
void help_alias(void);
void help_exit(void);
void help_help(void);
void help_setenv(void);
void help_env(void);
void help_unsetenv(void);
void help_history(void);

int proc_file_commands(char *file_path, int *exe_ret);

#endif
