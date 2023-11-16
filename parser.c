#include "shell.h"

/**
 * is_path_form - Checks if the given filename is a path.
 * @data: The data structure pointer.
 *
 * Return: SUCCESS if it's a path, FAIL otherwise.
 */
int is_path_form(sh_t *data)
{
    if (_strchr(data->args[0], '/') != 0)
    {
        data->cmd = _strdup(data->args[0]);
        return (SUCCESS);
    }
    return (FAIL);
}

#define DELIMITER ":"

/**
 * is_short_form - Checks if the given filename is in short form.
 * @data: The data structure pointer.
 */
void is_short_form(sh_t *data)
{
    char *path, *token, *_path;
    struct stat st;
    int exist_flag = 0;

    path = _getenv("PATH");
    _path = _strdup(path);
    token = strtok(_path, DELIMITER);

    while (token)
    {
        data->cmd = _strcat(token, data->args[0]);

        if (stat(data->cmd, &st) == 0)
        {
            exist_flag = 1;
            break;
        }

        free(data->cmd);
        token = strtok(NULL, DELIMITER);
    }

    if (exist_flag == 0)
    {
        data->cmd = _strdup(data->args[0]);
    }

    free(_path);
}

#undef DELIMITER

/**
 * is_builtin - Checks if the command is a built-in.
 * @data: A pointer to the data structure.
 *
 * Return: SUCCESS if it's a built-in, NEUTRAL otherwise.
 */
int is_builtin(sh_t *data)
{
    blt_t blt[] = {
        {"exit", abort_prg},
        {"cd", change_dir},
        {"help", display_help},
        {NULL, NULL}
    };

    int i = 0;

    while ((blt + i)->cmd)
    {
        if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
            return (SUCCESS);
        i++;
    }

    return (NEUTRAL);
}
