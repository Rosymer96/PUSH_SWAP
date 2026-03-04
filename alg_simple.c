/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/04 13:40:05 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_data *data)
{
	int	f;
	int	s;
	int	t;

	if (get_len_a(*a) != 3)
		return ;
	f = (*a)->number;
	s = (*a)->next->number;
	t = (*a)->next->next->number;
	if (f > s && f < t)
		sa(*a, data);
	else if (f > s && s > t)
	{
		sa(*a, data);
		rra(a, data);
	}
	else if (f > s && s < t)
		ra(a, data);
	else if (f < s && s > t && f < t)
	{
		sa(*a, data);
		ra(a, data);
	}
	else if (f < s && s > t && f > t)
		rra(a, data);
}

static void	move_to_top(t_stack **a, int min, t_data *data, int size)
{
	int	pos;

	pos = get_position(*a, min);
	if (pos <= size / 2)
	{
		while ((*a)->number != min)
			ra(a, data);
	}
	else
	{
		while ((*a)->number != min)
			rra(a, data);
	}
}

void	simple(t_stack **a, t_stack **b, t_data *data)
{
	int	min;
	int	init_size;

	init_size = data->size;
	while (init_size > 3)
	{
		min = find_min_value(*a);
		move_to_top(a, min, data, init_size);
		pb(a, b, data);
		init_size--;
	}
	sort_three(a, data);
	while (*b)
		pa(a, b, data);
}

