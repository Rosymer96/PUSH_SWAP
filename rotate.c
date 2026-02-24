/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:43:04 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/24 12:21:06 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate(t_stack **lst)
{
    t_stack *tmp;
    t_stack *last;

    if (!*lst || !(*lst)->next)
        return ;
    tmp = (*lst)->next; //guardo segundo nodo
	last = ft_lstlast(*lst); //busco el último nodo
	(*lst)->next = NULL; //desconecto primer nodo
	last->next = *lst; //conecto primer nodo al último
	*lst = tmp; //arreglo el head, apunto al segundo nodo
}

void    ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n"); //podemos usar write
}

void    rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void    rr(t_stack **a, t_stack **b)
{
    if (!*a || !*b)
        return ;
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}