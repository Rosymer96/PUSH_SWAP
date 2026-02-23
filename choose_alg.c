/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:06:40 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/23 18:11:37 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	**get_stack_a(t_data *data) //genera la lista que enviaremos al algoritmo
{
	t_stack	**a = NULL;
	t_stack	*node;
	int		i;

	i = 0;
	while (i < data->size)
	{
		node = ft_lstnew(data->stack_a[i], i);
		printf("[%i]", node->number);
		ft_lstadd_back(a, node);
		i++;
	}
	printf("\n");
	return (a);
}

void	choose_algorithm(t_data *data) //escoge algoritmo según flags
{
	if (data->strategy == 0)
		adaptive(data);
	else if (data->strategy == 1)
		simple(get_stack_a(data));
	else if (data->strategy == 2)
		medium(get_stack_a(data));
	else if (data->strategy == 3)
		complex(get_stack_a(data));
}

//testea el código
/*
static void init_data(t_data *data)
{
    data->size = 5;

    data->stack_a = malloc(sizeof(int) * data->size);
    if (!data->stack_a)
        return;

    data->stack_a[0] = 1;
    data->stack_a[1] = 2;
    data->stack_a[2] = 3;
    data->stack_a[3] = 87;
	data->stack_a[4] = 23;

    data->strategy = 0;
    data->bench_mode = 0;
    data->disorder = 0.0;
}

#include <stdio.h>

int	main(void)
{
	t_data	data;

	init_data(&data);
	choose_algorithm(&data);
	return (0);
}*/