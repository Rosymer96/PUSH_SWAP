/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:46:26 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/25 11:32:23 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //para las comprobaciones de en medio de la función, luego se borran

//testea que llegue bien al algoritmo

void	simple(t_stack **a)
{
	(void)a;
	printf("simple");
}

void	medium(t_stack **a)
{
	(void)a;
	printf("medium");
}

void	complex(t_stack **a)
{
	(void)a;
	printf("complex");
}

void	adaptive(t_data *data, double disorder) //algoritmo adaptativo, escoge cuál se usa en función del índice de desorden
{
	//double	disorder;

	//disorder = get_disorder(data->stack_a, data->size); //anadir en el main antes de todos los argumentos
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
