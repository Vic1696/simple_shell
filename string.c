#include "shell.h"

/**
 * _strcat - Concatenates two strings in a path form.
 * @first: The first given destination.
 * @second: The second given source.
 *
 * Return: A pointer to the newly concatenated string, or NULL on failure.
 */
char *_strcat(char *first, char *second)
{
    int len1, len2, i = 0, j = 0;
    char *result;

    if (first == NULL || second == NULL)
        return NULL;

    len1 = _strlen(first);
    len2 = _strlen(second);

    result = malloc((len1 + len2 + 2) * sizeof(char));
    if (!result)
        return NULL;

    *result = '\0';

    while (first[j])
        result[i++] = first[j++];

    result[i++] = '/';

    j = 0;
    while (second[j])
        result[i++] = second[j++];

    result[i] = '\0';
    return result;
}

/**
 * _strlen - Finds the length of a given string.
 * @str: The given string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
    int len;

    if (str == NULL)
        return 0;

    for (len = 0; str[len]; len++)
        ;

    return len;
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first given string.
 * @s2: The second given string.
 *
 * Return: A positive number if different, 0 if identical.
 */
int _strcmp(char *s1, char *s2)
{
    int cmp = 0, i;

    if (s1 == NULL || s2 == NULL)
        return 1;

    for (i = 0; s1[i] && s2[i]; i++)
    {
        if (s1[i] != s2[i])
        {
            cmp = s1[i] - s2[i];
            break;
        }
    }

    return cmp;
}

/**
 * _strchr - Locates a character in a given string.
 * @str: The given string.
 * @c: The given character.
 *
 * Return: A pointer to the first occurrence of c, or NULL if not found.
 */
char *_strchr(char *str, char c)
{
    if (str == NULL)
        return NULL;

    for (; *str; str++)
        if (*str == c)
            return str;

    return NULL;
}

/**
 * _strdup - Duplicates a string.
 * @str: The given string.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(char *str)
{
    char *dupl;

    if (str == NULL)
        return NULL;

    dupl = malloc(_strlen(str) + 1);
    if (dupl == NULL)
        return NULL;

    _strcpy(dupl, str);
    return dupl;
}
