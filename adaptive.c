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

void	adaptive(t_data *data, double disorder) //algoritmo adaptativo, escoge cuál se usa en función del índice de desorden
{
	printf("adaptive: %f\n", disorder);
	if (disorder == 0.0)
		return ;
	if (disorder < 0.2)
		simple(get_stack_a(data));
	else if (0.2 <= disorder && disorder < 0.5)
		medium(get_stack_a(data));
	else if (disorder >= 0.5)
		complex(get_stack_a(data));
}
