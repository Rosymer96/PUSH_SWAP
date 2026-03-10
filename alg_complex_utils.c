/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/10 10:57:22 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_stack *a, int b_idx)
{
	t_stack	*tmp_a;
	int		target_idx;
	int		target_pos;

	tmp_a = a;
	target_idx = 2147483647;
	target_pos = -1;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_pos == -1)
		return (find_min_pos(a));
	return (target_pos);
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;

	tmp_b = b;
	while (tmp_b)
	{
		tmp_b->target_pos = get_target(a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}

void	final_rot(t_stack **a, t_data *data)
{
	int	pos_min;
	int	size_a;

	set_position(*a);
	size_a = get_lst_size(*a);
	pos_min = find_min_pos(*a);
	if (pos_min <= size_a / 2)
	{
		while (pos_min-- > 0)
			ra(a, data);
	}
	else
	{
		pos_min = size_a - pos_min;
		while (pos_min-- > 0)
			rra(a, data);
	}
}

void	push_non_lis(t_stack **a, t_stack **b, t_data *data)
{
	int	medium_idx;
	int	size_a;

	medium_idx = data->size / 2;
	size_a = get_lst_size(*a);
	while (size_a > 0 && get_lst_size(*a) > data->lis_size)
	{
		if (!is_in_lis((*a)->number, data))
		{
			pb(a, b, data);
			if ((*b)->index > medium_idx && get_lst_size(*b) > 1)
				rb(b, data);
		}
		else
			ra(a, data);
		size_a--;
	}
}
