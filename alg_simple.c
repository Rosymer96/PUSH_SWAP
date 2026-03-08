/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/06 18:39:03 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_data *data)
{
	int	f;
	int	s;
	int	t;

	if (get_lst_size(*a) != 3)
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

static void	move_to_top(t_stack **a, int idx, t_data *data, int size)
{
	int	pos;

	pos = get_position(*a, idx);
	if (pos <= size / 2)
	{
		while ((*a)->index != idx)
			ra(a, data);
	}
	else
	{
		while ((*a)->index != idx)
			rra(a, data);
	}
}

void	simple(t_stack **a, t_stack **b, t_data *data)
{
	int	idx;
	int	init_size;

	idx = 0;
	init_size = data->size;
	while (init_size > 3)
	{
		move_to_top(a, idx, data, init_size);
		pb(a, b, data);
		init_size--;
		idx++;
	}
	sort_three(a, data);
	while (*b)
		pa(a, b, data);
}