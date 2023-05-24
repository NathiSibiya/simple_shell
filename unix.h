#ifndef _UNIX_H_
#define _UNIX_H_


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

#include <fcnt1.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>


