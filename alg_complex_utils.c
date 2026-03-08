/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/25 13:54:38 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_stack *a, int b_idx)
{
	t_stack	*tmp_a;
	int	target_idx;
	int	target_pos;

	tmp_a = a;
	target_idx = 2147483647;
	target_pos = -1;
	// 1. Buscamos el "mínimo superior"
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

void find_target(t_stack *a, t_stack *b)
{
	t_stack *tmp_b;

	tmp_b = b;
	while (tmp_b)
	{
		tmp_b->target_pos = get_target(a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}


void final_rot(t_stack **a, t_data *data)
{
	int pos_min;
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
		while (pos_min -- > 0)
			rra(a, data);
	}
}
