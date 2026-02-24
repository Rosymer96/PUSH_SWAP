/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:45:55 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/24 12:21:09 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *lst)
{
	int tmp;

	if (!lst)
		return ;
	tmp = lst->number; //guardo el número del primer nodo de a
	lst->number = (lst->next)->number; //el nº del primer nodo pasa a ser el segundo
	(lst->next)->number = tmp; //el nº del segundo nodo pasa a ser el del primero (guardado)
	tmp = lst->index; //lo mismo pero con el index
	lst->index = (lst->next)->index;
	(lst->next)->index = tmp;
}
void	sa(t_stack *a)
{
	int tmp;

	swap(a);
	ft_printf("sa\n");//podemos usar write
}

void	sb(t_stack *b)
{
	int tmp;

	swap(b);
	ft_printf("sa\n");
}

void    ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}