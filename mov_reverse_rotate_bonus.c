/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverse_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:57:55 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:32:28 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_stack	*find_new_last(t_stack *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	rev_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!*lst || !(*lst)->next)
		return ;
	new_last = find_new_last(*lst);
	last = new_last->next;
	last->next = *lst;
	new_last->next = NULL;
	*lst = last;
}

void	rra(t_stack **a, t_data *data)
{
	rev_rotate(a);
	data->stats.rra++;
	data->stats.total++;
}

void	rrb(t_stack **b, t_data *data)
{
	rev_rotate(b);
	data->stats.rrb++;
	data->stats.total++;
}

void	rrr(t_stack **a, t_stack **b, t_data *data)
{
	rev_rotate(a);
	rev_rotate(b);
	data->stats.rrr++;
	data->stats.total++;
}
