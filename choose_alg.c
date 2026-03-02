/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:06:40 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/27 11:52:44 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_code(t_stack **a, t_data *data)
{
	if (data->disorder == 1)
	{
		sa((*a), data);
		rra(a, data);
	}
	else if (data->disorder >= 0.6)
	{
		if ((*a)->number > (*a)->next->number)
			ra(a, data);
		else
			rra(a, data);
	}
	else if (data->disorder <= 0.6)
		sa((*a), data);
}

static void	send_to_algorithm(t_stack **a, t_stack **b, t_data *data)
{
	if (data->strategy == 1)
		adaptive(a, b, data);
	else if (data->strategy == 2)
		simple(a, b, data);
	else if (data->strategy == 3)
		medium(a, b, data);
	else if (data->strategy == 4)
		complex(a, b, data);
}

void	choose_algorithm(t_data *data) //escoge algoritmo según flags
{
	t_stack	*a;
	t_stack	*b;
	
	if (data->disorder == 0.0)
		return ;
	a = get_stack_a(data);
	if (!a)
		return ;
	b = get_stack_b(data);
	/*if (!b)
	{
		free_stack(&a);
		return ;
	}*/
	if (data->size == 2)
		sa(a, data);
	else if (data->size == 3)
		hard_code(&a, data);
	else
		send_to_algorithm(&a, &b, data);

	t_stack *tmp;
	tmp = a;
	while (tmp)
	{
		printf("[%i]", tmp->number);
		tmp = tmp->next;
	}
	free_stack(&a);
	free_stack(&b);
}

/*
static void	init_data(t_data *data)
{
    data->size = 3;
    data->stack_a = malloc(sizeof(int) * data->size);
    if (!data->stack_a)
        return ;
    data->stack_a[0] = 2;
    data->stack_a[1] = 1;
    data->stack_a[2] = 3;
    data->strategy = 0;
    data->bench_mode = 0;
    data->disorder = get_disorder(data->stack_a, data->size);
}

#include <stdio.h>

int	main(void)
{
	t_data	data;

	init_data(&data);
	printf("disorder: %f\n", data.disorder);
	choose_algorithm(&data);
	return (0);
}*/