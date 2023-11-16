#include "shell.h"

/**
 * _fetch_env - retrieve the environment variable
 * @target: the target variable
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
char *_fetch_env(char *target)
{
	char **env_cursor, *env_ptr, *name_ptr;

	env_cursor = environ;
	while (*env_cursor)
	{
		env_ptr = *env_cursor;
		name_ptr = target;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		env_cursor++;
	}
	return (NULL);
}

/**
 * handle_signal - process interrupt signal
 * @signal_num: the signal identifier
 *
 * Return: void
 */
void handle_signal(int signal_num)
{
	if (signal_num == SIGINT)
	{
		PRINT("\n");
		PRINT(PROMPT);
	}
}

/**
 * initialize_array - populate an array with elements
 * @array: the target array
 * @element: the specified element
 * @length: the length of the array
 *
 * Return: pointer to the populated array
 */
void *initialize_array(void *array, int element, unsigned int length)
{
	char *ptr = array;
	unsigned int i = 0;

	while (i < length)
	{
		*ptr = element;
		ptr++;
		i++;
	}
	return (array);
}

/**
 * reverse_sequence - reverse the order of array elements
 * @sequence: the input array
 * @length: the length of the array
 *
 * Return: void
 */
void reverse_sequence(char *sequence, int length)
{
	int i;
	char temp;

	for (i = 0; i < (length / 2); i++)
	{
		temp = sequence[i];
		sequence[i] = sequence[(length - 1) - i];
		sequence[(length - 1) - i] = temp;
	}
}

/**
 * update_index - update the command index
 * @data: a pointer to the data structure
 *
 * Return: void
 */
void update_index(sh_t *data)
{
	data->index += 1;
}
