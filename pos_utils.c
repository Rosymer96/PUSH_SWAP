/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/11 11:55:04 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i++;
		stack = stack->next;
	}
}

int	find_min_pos(t_stack *a)
{
	int	min_idx;
	int	min_pos;

	min_idx = 2147483647;
	min_pos = 0;
	while (a)
	{
		if (a->index < min_idx)
		{
			min_idx = a->index;
			min_pos = a->pos;
		}
		a = a->next;
	}
	return (min_pos);
}

int	find_max_pos(t_stack *b)
{
	int	tmp;
	int	pos;
	int	i;

	tmp = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (tmp < b->index)
		{
			tmp = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

int	get_position(t_stack *a, int idx)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index == idx)
			return (pos);
		pos++;
		a = a->next;
	}
	return (pos);
}
