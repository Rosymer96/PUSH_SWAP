/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:54 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/03 20:41:49 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_a(t_data *data)
//genera la lista que enviaremos al algoritmo
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	i = 0;
	a = NULL;
	while (i < data->size)
	{
		node = ft_lstnew(data->stack_a[i], i);
		ft_lstadd_back(&a, node);
		i++;
	}
	return (a);
}

t_stack *get_stack_b(t_data *data)
{
	t_stack *b;
	t_stack	*node;
	int	i;

	i = 0;
	b = NULL;
	while (i < data->size)
	{
		node = ft_lstnew(NULL, 0);
		ft_lstadd_back(&b, node);
		i++;
	}
	return (b);
}