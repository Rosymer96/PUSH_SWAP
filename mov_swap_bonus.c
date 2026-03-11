/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:45:55 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:32:50 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_stack *lst)
{
	int	tmp;

	if (!lst)
		return ;
	tmp = lst->number;
	lst->number = (lst->next)->number;
	(lst->next)->number = tmp;
}

void	sa(t_stack *a, t_data *data)
{
	swap(a);
	data->stats.sa++;
	data->stats.total++;
}

void	sb(t_stack *b, t_data *data)
{
	swap(b);
	data->stats.sb++;
	data->stats.total++;
}

void	ss(t_stack *a, t_stack *b, t_data *data)
{
	swap(a);
	swap(b);
	data->stats.ss++;
	data->stats.total++;
}
