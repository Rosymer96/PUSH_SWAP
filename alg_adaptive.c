/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_adaptive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:46:26 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/06 18:40:09 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack **a, t_stack **b, t_data *data)
{
	if (data->size <= 5)
	{
		simple(a, b, data);
		return ;
	}
	if (data->size <= 50)
	{
		if (data->disorder < 0.15)
			simple(a, b, data);
		else
			medium(a, b, data);
		return ;
	}
	if (data->size <= 200)
	{
		if (data->disorder < 0.1)
			simple(a, b, data);
		else
			medium(a, b, data);
		return ;
	}
	complex(a, b, data);
}
