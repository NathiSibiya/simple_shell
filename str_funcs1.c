#include "shell.h"

int _strlen(cont char *s);
char *_strcpy(char *dest,const char *src);
char *_strcat(char *dest, const *src);
char *strncat(char *dest, const char *src, size_t n);

/**
 * _strlen - brings back the length of a string.
 * @s: this is a pointer to the characters string.
 *
 * Return: length of the characters string.
 */
int _strlen(const char *s)
{
	int length = 0;
	if(!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _strcat - this concantenates two strings.
 * @dest: this is a pointer to destination string.
 * @src: this is a pointer to source string.
 *
 * Return: this is a pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp = src;
	
	while (*destTemp != '\0')
		destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strncat - this concantenates two strings where n number
 * 		of bytes are copied from source.
 * @dest: this is pointer  to destination string.
 * @src:this is pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: the pointer to destination string.
 */
char *strncat(char*dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;
	for (i = 0; i < n && src[i]!= '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

