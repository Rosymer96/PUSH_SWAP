#include "push_swap.h"

void free_and_exit(t_data *data, char **nums_split, int status)
{
    if (nums_split)
        free_split(nums_split);
    if (data && data->stack_a)
    {
        free(data->stack_a);
        data->stack_a = NULL;
    }
    if (status == 1)
        write(2, "Error\n", 6);
    exit(status);
}


void free_split(char **words)
{
    size_t i;

    if (!words)
        return;
    i = 0;
    while (words[i])
    {
        free(words[i]);
        i++;
    }
    free(words);
}