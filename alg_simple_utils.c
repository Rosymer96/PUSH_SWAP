/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/04 14:19:41 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	int	min_val;
	int	min_pos;
	int	i;

	min_val = a->number;
	min_pos = 0;
	i = 0;
	while (a)
	{
		if (a->number < min_val)
		{
			min_val = a->number;
			min_pos = i;
		}
		a = a->next;
		i++;
	}
	return (min_pos);
}
/*
int	find_min_value(t_stack *a)
{
	int	min;

	min = a->number;
	while (a)
	{
		if (a->number < min)
			min = a->number;
		a = a->next;
	}
	return (min);
}*/

int	get_len_a(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
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
