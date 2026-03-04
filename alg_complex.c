/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:57 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/27 11:52:51 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void mark_index_lis(t_stack *a, int *lis_array, int lis_size)
{
	t_stack *tmp;
	int	i;

	tmp = a;
	while(tmp)
	{
		tmp->index = 0;
		i = 0;
		while (i < lis_size)
		{
			if (tmp->number == lis_array[i])
			{
				tmp->index = -1; //marcamos los LIS
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static int	is_in_lis(int index, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lis_size)
	{
		if (data->lis_size[i] == index)
			return (1)
		i++;
	}
	return (0);
}
//movemos los que no son LIS a B
static void push_non_lis(t_stack **a, t_stack **b, t_data *data)
{
	int medium_idx;

	medium_idx = data->size / 2;

	while (get_len_a(*a) > data->lis_size)
	{
		if (is_in_lis(data->stack_a))
			pb(a, b, data);
		else
			ra(a, data);
		i++;
	}
}

void	complex(t_stack **a, t_stack **b, t_data *data)
{
	/*int *lis_array;
	int lis_size;*/

	data->lis_array = get_lis_ind(data, data->lis_size);

	if (!data->lis_array) 
		//liberar data return ;
	//no es necesario mark_index_lis(*a, data->lis_array, data->lis_size);
	//el array ya no es necesario
	//free(lis_array);
	//movemos los que no son de la LIS a b
	push_non_lis(a, b, data);
	//calcular greedy para regresar a A;


	//Rotamos en caso sea necesario
	final_rot(a, data);
}

