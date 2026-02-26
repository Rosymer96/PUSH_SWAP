/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:46:26 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/25 13:41:16 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_data *data, t_stack **a, t_stack **b) //algoritmo adaptativo, escoge cuál se usa en función del índice de desorden
{
	printf("adaptive: %f\n", data->disorder);
	if (data->disorder == 0.0)
		return ;
	if (data->disorder < 0.2)
		simple(stack_a, stack_b);
	else if (0.2 <= data->disorder && data->disorder < 0.5)
		medium(stack_a, stack_b);
	else if (data->disorder >= 0.5)
		complex(stack_a, stack_b);
}
