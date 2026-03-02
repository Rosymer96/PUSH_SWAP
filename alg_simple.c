/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/27 11:52:48 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_code_3(t_stack **a, t_data *data)
{
	int first = (*a)->number;
	int second = (*a)->next->number;
	int third = (*a)->next->next->number;

	if (first > second && second < third && first < third)
		sa((*a), data); // Caso: 2 1 3
	else if (first > second && second > third)
	{
		sa((*a), data); // Caso: 3 2 1
		rra(a, data);
	}
	else if (first > second && second < third && first > third)
		ra(a, data);    // Caso: 3 1 2
	else if (first < second && second > third && first < third)
	{
		sa((*a), data); // Caso: 1 3 2
		ra(a, data);
	}
	else if (first < second && second > third && first > third)
		rra(a, data);   // Caso: 2 3 1
}

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

static void push_non_lis(t_stack **a, t_stack **b, t_data *data)
{
    int size;
    int rotations;

    size = get_len_a(*a);
    rotations = size;
    //intentamos mandar solo los que NO son LIS
    while (rotations > 0 && size > 3)
    {
        if ((*a)->index != -1)
        {
            pb(a, b, data);
            size--;
        }
        else
            ra(a, data);
        rotations--;
    }
    // si aún sobran (>3), mandamos lo que sea para desbloquear
    while (size > 3)
    {
        pb(a, b, data);
        size--;
    }
}

void	simple(t_stack **a, t_stack **b, t_data *data)
{
	int *lis_array;
	int lis_size;

	lis_array = get_lis_ind(data, &lis_size);

	if (!lis_array) 
		return ;
	mark_index_lis(*a, lis_array, lis_size);
	//el array ya no es necesario
	free(lis_array);
	//movemos los que no son de la LIS a b
	push_non_lis(a, b, data);
	hard_code_3(a, data);
	//regreseamos a "a" en su orden correcto
	back_to_a(a, b, data);
	final_rot(a, data);
}

