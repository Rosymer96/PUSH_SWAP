/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:43:49 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/24 12:20:57 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n"); //podemos usar write también
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if(!*a)
		return ;
	tmp = *a; //guardo el primer nodo de a
	*a = tmp->next; //modifico el top de a
	tmp->next = *b; //primer nodo de a (antiguo) apunta al top de b
	*b = tmp; //primer nodo de a (antiguo) se convierte en top de b
	ft_printf("pb\n");
}