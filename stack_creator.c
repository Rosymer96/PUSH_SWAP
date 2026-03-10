/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:54 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/10 10:58:51 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_data *data, int nbr)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < data->size)
	{
		if (nbr > data->stack_a[i])
			index++;
		i++;
	}
	return (index);
}

t_stack	*get_stack_a(t_data *data)
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	i = 0;
	a = NULL;
	while (i < data->size)
	{
		node = ft_lstnew(data->stack_a[i], get_index(data, data->stack_a[i]),
				i);
		ft_lstadd_back(&a, node);
		i++;
	}
	return (a);
}
