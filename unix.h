#ifndef UNIX_H
#define UNIX_H


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


#endif
