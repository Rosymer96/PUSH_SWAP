/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:45:55 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/27 12:48:13 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *lst)
{
	int	tmp;

	if (!lst)
		return ;
	tmp = lst->number; //guardo el número del primer nodo de a
	lst->number = (lst->next)->number; //el nº del primer nodo pasa a ser el segundo
	(lst->next)->number = tmp; //el nº del segundo nodo pasa a ser el del primero (guardado)
	tmp = lst->index; //lo mismo pero con el index
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
