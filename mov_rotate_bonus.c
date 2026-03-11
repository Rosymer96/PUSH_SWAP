/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:43:04 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:32:38 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	last = ft_lstlast(*lst);
	(*lst)->next = NULL;
	last->next = *lst;
	*lst = tmp;
}

void	ra(t_stack **a, t_data *data)
{
	rotate(a);
	data->stats.ra++;
	data->stats.total++;
}

void	rb(t_stack **b, t_data *data)
{
	rotate(b);
	data->stats.rb++;
	data->stats.total++;
}

void	rr(t_stack **a, t_stack **b, t_data *data)
{
	if (!*a || !*b)
		return ;
	rotate(a);
	rotate(b);
	data->stats.rr++;
	data->stats.total++;
}
