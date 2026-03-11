/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:44 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/11 11:55:40 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_stack_b(t_stack **a, t_stack **b, int k, t_data *data)
{
	int	i;

	i = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= k + i)
		{
			pb(a, b, data);
			if ((*b)->index <= i)
				rb(b, data);
			i++;
		}
		else
			ra(a, data);
	}
}

static void	back_to_stack_a(t_stack **a, t_stack **b, t_data *data)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (*b)
	{
		tmp = *b;
		while (tmp->index != data->size - 1 - i)
			tmp = tmp->next;
		if (find_max_pos(*b) <= (get_lst_size(*b) / 2))
		{
			while ((*b)->index != tmp->index)
				rb(b, data);
		}
		else
		{
			while ((*b)->index != tmp->index)
				rrb(b, data);
		}
		pa(a, b, data);
		i++;
	}
}

void	medium(t_stack **a, t_stack **b, t_data *data)
{
	int	k;

	k = (data->size / 20) + 7;
	push_to_stack_b(a, b, k, data);
	back_to_stack_a(a, b, data);
}
