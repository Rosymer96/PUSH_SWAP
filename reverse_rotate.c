/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:57:55 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/24 12:21:02 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *find_new_last(t_stack *lst)
{
    if (!lst || !lst->next)
        return (NULL);
    while (lst->next->next != NULL)
        lst = lst->next;
    return (lst);
}

static void    rev_rotate(t_stack **lst)
{
    t_stack *last;
    t_stack *new_last;

    if (!*lst || !(*lst)->next)//comprueba que no haya 0 o 1 nodo
        return ;
    new_last = find_new_last(*lst); //encuentra el penúltimo nodo
    last = new_last->next; //identifico último nodo
    last->next = *lst; //conecto el último al principio de la lista
    new_last->next = NULL; //el penúltimo nodo pasa a ser el último
    *lst = last; //el top apunta al último nodo (ahora está delante)
}

void    rra(t_stack **a)
{
    rev_rotate(a);
    ft_printf("rra\n"); //podemos usar write
}

void    rrb(t_stack **b)
{
    rev_rotate(b);
    ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_printf("rrr\n");
}