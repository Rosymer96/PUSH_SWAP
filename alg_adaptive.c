/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_adaptive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:46:26 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/26 23:07:07 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack **a, t_stack **b, double disorder) //algoritmo adaptativo, escoge cuál se usa en función del índice de desorden
{
	if (disorder < 0.2)
		simple(a, b);
	else if (0.2 <= disorder && disorder < 0.5)
		medium(a, b);
	else if (disorder >= 0.5)
		complex(a, b);
}
