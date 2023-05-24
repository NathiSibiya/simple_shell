#include "unix.h"
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);

/**
 * _strchr - this locates a character in a string.
 * @s: is the string to be searched.
 * @c: is the character to be located.
 *
 * Return: when c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}

/**
 * _strspn - this gets the length of a prefix substring.
 * @s: this is the string to be searched.
 * @accept: is the prefix to be measured.
 *
 * Return:  number of bytes in s which
 *         consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - this compares two strings.
 * @s1:is the first string to be compared.
 * @s2:is the second string to be compared.
 *
 * Return: is the positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - this compare two strings.
 * @s1: this is a pointer to a string.
 * @s2: this is a pointer to a string.
 * @n: the first n bytes of the strings to compare.
 *
 * Return: Less than 0 if s1 is shorter than s2.
 *         0 if s1 and s2 match.
 *         Greater than 0 if s1 is longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
