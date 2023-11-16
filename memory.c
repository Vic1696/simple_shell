#include "shell.h"

/**
 * _realloc - Reallocates memory block
 * @ptr: Pointer to the previous memory
 * @old_size: The old size
 * @new_size: The new size
 *
 * Return: A pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *result;

    if (new_size == old_size)
        return (ptr);

    if (new_size == 0 && ptr)
    {
        free(ptr);
        return (NULL);
    }

    result = malloc(new_size);

    if (result == NULL)
        return (NULL);

    if (ptr == NULL)
    {
        _memset(result, '\0', new_size);
    }
    else
    {
        _memcpy(result, ptr, old_size);
        free(ptr);
    }

    return (result);
}

/**
 * _memset - Fills a memory with a constant byte
 * @s: Pointer to memory area
 * @byt: Constant byte
 * @n: First n bytes
 *
 * Return: A pointer to a character
 */
char *_memset(char *s, char byt, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        s[i] = byt;
    }

    return (s);
}

/**
 * free_data - Frees data
 * @data: The data structure
 *
 * Return: Always returns 0
 */
int free_data(sh_t *data)
{
    free(data->line);
    data->line = NULL;

    free(data->args);
    data->args = NULL;

    free(data->cmd);
    data->cmd = NULL;

    free(data->error_msg);
    data->error_msg = NULL;

    return (0);
}

/**
 * _memcpy - Copies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }

    return (dest);
}
