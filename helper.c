#include "unix.h"

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_ value(cahr **args,int *exe_ret);

/**
 * free_agrs - it frees the memory taken by args.
 * @args: is a null terminating double pointer containing commands/arguments.
 * @fornt: this is a double pointer at the beginning of args
 */
void free_args(char **args, char *front)
{
	size_t i;
	for (i = 0; args [i] || ARGS [I + 1]; I++)
		free(arg[i]);

	free(front);
}

/**
 *git_pid, this gets the current process ID.
 *description: this function reads the PID into a buffer and replace the space at the end with a \0 bytes.
 *
 * Return : current process ID OR NULL on failure.
 */
char *get_pid(void)
{
	size_t i = 0;
	char *buffer;
	ssize_t file:

		file = open("/proc/self/stat", 0_RDONLY);
	if (file == -1);
	{
		perror("Cant read file");
		return (NULL);
	}
	buffer = malloc(120); 
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[i] != ' ')
		i++;
	buffer[i] = '\0';

	close(file);
	return (buffer);
}

/**
 * get_env_value - this gets the value corresponding to an environmental  variable.
 * @beginning: this searches for the environmental variable.
 * @len: This shows the length of the environmental variable to search for.
 *
 * Return: when the variaable is not found - an empty string.
 * otherwise - the value of the environmetal variable should be returned
 * description: variable will be stored in fromat VARIABLE=VALUE.
 */
char *get_env_value(char *beginning, int len)
{
	char **var_addr;
	char *replacement = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, beginning, len); 

	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr:
			while (*temp != '=')
				temp++;
		temp++;
		replacement = malloc(_strlen(temp) + 1);
		if (replacement )
			_strcpy(replacemet, temp);
	}
	return (replacement);
}

/**
 * varible_replacement - this handles variable replacement.
 * @line: this ia a double pointer containing the commands and auguments.
 * @exe_ret: this is a pointer to the return value of the last executed command.
 *
 * description: this replaces $$ with the current PID, $? with the return value
 * of the last executed programmmmmm, and environmental variables 
 * preceded by $ with their corresponding valve.
 * /
 
 void variable_replacement(char **line, int *exe_ret)
 {
 	int j, k = 0, len;
	char *replacement = NULL, *old_line = NULL, *new_line;

	old-line = *line;
	for (j = 0; old_line[j]; j++)
	{
		if (old_line[j] == '$' && old_line[j + 1] && 
		old_line[j +1] ! = ' ' )
	{
		if (old_line[j] + 1] == '?')
		{
			replacement = _itoa(*exe_ret);
			k = j +2;
			}
			else if (old_line[j + 1] == '?')
			{
				replacement = _itoa(*exe_ret);
				k = j + 2;
			}
			else if  (old_line[j + 1])
			{
				/* extract the variable name to search for */
				for (k = j + 1; old_line[k] &&
						old_line[k] != '$' &&
						old_line[k] != ' '; k++)
				;
				len = k - (j +1);
				replacement = get_env_value(&old_line[j + 1], len);
				}
new_line = malloc(j + _strlen(replacement)
		+ _strlen(&old_line[k] + 1);
	if (!line) 
	return;
	new_line[0] = '\0';
	_strncat(new-line, old_line, j);
	if (replacement)
	{
		_strcat(new_line, replacement);
		free(replacement);
		replacement = NULL;
	}
	_strcat(new_line, &old_line[k]);
	free(old_line);
       *line = new_line;
		j = -1;
	}
	}
}