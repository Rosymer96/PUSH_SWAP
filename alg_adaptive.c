/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_adaptive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:46:26 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/03 23:32:31 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack **a, t_stack **b, t_data *data) //algoritmo adaptativo, escoge cuál se usa en función del índice de desorden
{
	if (data->disorder < 0.2)
		simple(a, b, data);
	else if (0.2 <= data->disorder && data->disorder < 0.5)
		medium(a, b, data);
	else if (data->disorder >= 0.5)
		complex(a, b, data);
}
