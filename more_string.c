#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @source: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *source)
{
    int i;

    for (i = 0; source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }

    dest[i] = '\0';
    return (dest);
}

/**
 * _isalpha - Checks if the input is a letter.
 * @c: The character to be checked.
 *
 * Return: 1 if it is a letter, 0 otherwise.
 */
int _isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return (SUCCESS);
    }

    return (FAIL);
}
