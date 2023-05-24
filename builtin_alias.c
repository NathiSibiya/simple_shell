#include "unix.h"

int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);


/**
 * shellby_alias - prints all aliases or set
 * @args: array of arguments
 * @front: double pointer to beginning of args
 *
 * Return: -1 if error, else 0
 */

int shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int a, ret = 0;
	char *value;

	if (!args[0])
	{
		while (temp)
		{
			print_alias(temp);
			temp = temp->next;
		}
		return (ret);
	}
	for (a = 0; args[a]; a++)
	{
		temp = aliases;
		value = _strchr(args[a], '=');
		if (!value)
		{
			while (temp)
			{
				if (_strcmp(args[a], temp->name) == 0)
				{
					print_alias(temp);
					break;
				}
				temp = temp->next;
			}
			if (!temp)
				ret = create_error(args + a, 1);
		}
		else
			set_alias(args[a], value);
	}
	return (ret);
}

/**
 * set_alias - set an existing alias with a new value
 * @var_name: name of alias
 * @value: value of the alias
 */

void set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases;
	int len, b, c;
	char *new_value;

	*value = '\0';
	value++;
	len = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (len + 1));
	if (!new_value)
		return;
	for (b = 0, c = 0; value[b]; b++)
	{
		if (value[b] != '\'' && value[b] != '"')
			new_value[c++] = value[b];
	}
	new_value[c] = '\0';
	while (temp)
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
		add_alias_end(&aliases, var_name, new_value);
}

/**
 * print_alias - prints alias
 * @alias: pointer to an alias
 */

void print_alias(alias_t *alias)
{
	char *alias_string;
	int len = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, len);
	free(alias_string);
}

/**
 * replace_aliases - replace matching aliases
 * @args: 2D pointer to arguments
 *
 * Return: 2D pointer to the arguments
 */

char **replace_aliases(char **args)
{
	alias_t *temp;
	int a;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (a = 0; args[a]; a++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[a], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));

				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, temp->value);
				free(args[a]);
				args[a] = new_value;
				a--;
				break;
			}
			temp = temp->next;
		}
	}
	return (args);
}

