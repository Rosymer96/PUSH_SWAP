/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:45:55 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/06 17:48:09 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *lst)
{
	int	tmp;

	if (!lst)
		return ;
	tmp = lst->number;
	lst->number = (lst->next)->number;
	(lst->next)->number = tmp;
	tmp = lst->index;
	lst->index = (lst->next)->index;
	(lst->next)->index = tmp;
}

void	sa(t_stack *a, t_data *data)
{
	swap(a);
	write(1, "sa\n", 3);
	data->stats.sa++;
	data->stats.total++;
}

void	sb(t_stack *b, t_data *data)
{
	swap(b);
	write(1, "sb\n", 3);
	data->stats.sb++;
	data->stats.total++;
}

void	ss(t_stack *a, t_stack *b, t_data *data)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	data->stats.ss++;
	data->stats.total++;
}
