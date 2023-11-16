#include "shell.h"

#define SET_OLD_WD(V) (V = strdup(_getenv("OLDPWD")))

/**
 * switch_directory - Changes the current working directory
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int switch_directory(sh_t *data) {
    char *home;
    int result = -1;

    home = _getenv("HOME");

    if (data->args[1] != NULL && strcmp(data->args[1], "-") == 0) {
        if (data->oldpwd == NULL) {
            SET_OLD_WD(data->oldpwd);
            result = chdir(home);
        } else {
            SET_OLD_WD(data->oldpwd);
            result = chdir(data->oldpwd);
        }
    } else if (data->args[1] == NULL) {
        SET_OLD_WD(data->oldpwd);
        result = chdir(home);
    } else {
        SET_OLD_WD(data->oldpwd);
        result = chdir(data->args[1]);
    }

    return result;
}

#undef GETCWD

/**
 * end_program - Terminates the program with the specified exit code
 * @data: Pointer to the shell data structure
 * Return: 0
 */
int end_program(sh_t *data) {
    int code = 0;
    int i = 0;

    if (data->args[1] != NULL) {
        while (data->args[1][i]) {
            if (!isdigit(data->args[1][i++])) {
                data->error_msg = strdup("Illegal number\n");
                return -1;
            }
        }

        code = atoi(data->args[1]);
    }

    free_data(data);
    exit(code);
}

/**
 * show_command_help - Displays the help menu for the specified command
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int show_command_help(sh_t *data) {
    int fd, fw, rd;
    char c;

    fd = open(data->args[1], O_RDONLY);
    if (fd < 0) {
        data->error_msg = strdup("No help topics match\n");
        return -1;
    }

    while ((rd = read(fd, &c, 1)) > 0) {
        fw = write(STDOUT_FILENO, &c, rd);
        if (fw < 0) {
            data->error_msg = strdup("Cannot write: permission denied\n");
            return -1;
        }
    }

    printf("\n");
    return 0;
}

/**
 * handle_builtin_commands - Handles built-in commands
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int handle_builtin_commands(sh_t *data) {
    builtin_cmd_t builtins[] = {
        {"exit", end_program},
        {"cd", switch_directory},
        {"help", show_command_help},
        {NULL, NULL}
    };
    int index = 0;

    while (builtins[index].cmd != NULL) {
        if (strcmp(data->args[0], builtins[index].cmd) == 0) {
            return builtins[index].func(data);
        }
        index++;
    }

    return -1;
}
