/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:06:40 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/06 17:41:20 by albben-a         ###   ########.fr       */
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

void	choose_algorithm(t_data *data)
{
	t_stack	*a;
	t_stack	*b;

	if (data->disorder == 0.0)
		return ;
	a = get_stack_a(data);
	if (!a)
		return ;
	b = NULL;
	if (data->size == 2)
		sa(a, data);
	else if (data->size == 3)
		hard_code(&a, data);
	else
		send_to_algorithm(&a, &b, data);
	free_stack(&a);
	free_stack(&b);
}
