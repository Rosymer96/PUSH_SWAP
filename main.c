/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/19 15:18:03 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void init_data(t_data *data)
{
    data->stack_a = NULL;
    data->size = 0;
    data->strategy = 0;
    data->bench_mode = 0;
    data->disorder = 0.0;
}

void free_and_exit(t_*data, char **nums_split, int status)
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

int main(int ac, char *av)
{
    t_data data;
    char *nums_split;
    int i;

    if (ac < 2)
        return (0);
    init_data(&data);
    i = 1;
    /* Mientras que comiencen con -- se va actualizando tanto el algoritmo y el bench ya que si hay varios algoritmos se va a coger el ultimo siempre */
    while(av[i] && is_flag(av[i]))
    {
        update_flag(&data, av[i]);
        i++;
    }
    /*Si solo hay flags termina sin devolver nadita*/
    if(!av[i])
        return (0);
    while (av[i])
    {
        nums_split = ft_split(av[i], ' ');
        if (!nums_split)
            free_and_exit(&data, NULL, 1);
        if (!process_num(nums_split, &data))
            free_and_exit(&data, nums_split, 1);
        free_split(nums_split);
        i++;
    }
    if (check_duplicates(data->stack_a, data->size))
        free_and_exit(&data, NULL, 1);
    /*Aqui envio la data a tu funcion ALBITA*/

    free_and_exit(&data, NULL, 0);
    return (0);
}
