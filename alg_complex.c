/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:57 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/06 18:04:26 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//movemos los que no son LIS a B
static void push_non_lis(t_stack **a, t_stack **b, t_data *data)
{
	int medium_idx;
	int	size_a;

	medium_idx = data->size / 2;
	size_a = get_lst_size(*a);

	while (size_a > 0 && get_lst_size(*a) > data->lis_size)
	{
		if (!is_in_lis((*a)->number, data))
		{
			pb(a, b, data);
			if ((*b)->index > medium_idx && get_lst_size(*b) > 1)
				rb(b, data);
		}
		else
			ra(a, data);
		size_a--;
	}
}

static void	calculate_costs(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = get_lst_size(a);
	size_b = get_lst_size(b);

	while (b)
	{
		if (b->pos <= size_b / 2)
			b->cost_b = b->pos;
		else
			b->cost_b = (size_b - b->pos) * -1;
		if (b->target_pos <= size_a / 2)
			b->cost_a = b->target_pos;
		else
			b->cost_a = (size_a - b->target_pos) * -1;
		b = b->next;
	}
} 

static void find_best_node(t_stack *b, t_stack **best_node)
{
	int	cost;
	int	low_cost;

	low_cost = 2147483647;
	while (b)
	{
		if ((b->cost_a > 0 && b->cost_b > 0) || (b->cost_a < 0 && b->cost_b < 0)) 
		{
			if (get_abs(b->cost_a) > get_abs(b->cost_b))
				cost = get_abs(b->cost_a);
			else	
				cost = get_abs(b->cost_b);
		}
		else
			cost = get_abs(b->cost_a) + get_abs(b->cost_b);
		if (cost < low_cost)
		{
			low_cost = cost;
			*best_node = b;
		}
		b = b->next;
	}
}

static void move_to_a_ind(t_stack **b, t_stack **a, t_stack *best_node, t_data *data)
{
	while (best_node->cost_a > 0)
	{
		ra(a, data);
		best_node->cost_a--;
	}
	while (best_node->cost_b > 0)
	{
		rb(b, data);
		best_node->cost_b--;
	}
	while (best_node->cost_a < 0)
	{
		rra(a, data);
		best_node->cost_a++;
	}
	while (best_node->cost_b < 0)
	{
		rrb(b, data);
		best_node->cost_b++;
	}
}

static void move_to_a_double(t_stack **b, t_stack **a, t_stack *best_node, t_data *data)
{
	while (best_node->cost_a > 0 && best_node->cost_b > 0)
	{
		rr(a, b, data);
		best_node->cost_a--;
		best_node->cost_b--;
	}
	while (best_node->cost_a < 0 && best_node->cost_b < 0)
	{
		rrr(a, b, data);
		best_node->cost_a++;
		best_node->cost_b++;
	}
	move_to_a_ind(b, a, best_node, data);
	pa(a, b, data);
}


void	complex(t_stack **a, t_stack **b, t_data *data)
{
	t_stack *best_node;

	data->lis_array = get_lis_ind(data);


	if (!data->lis_array) 
		free_and_exit(data, NULL, 1);
	push_non_lis(a, b, data);
	//calcular greedy para regresar a A;
	while(*b)
	{
		set_position(*a);
		set_position(*b);
		find_target(*a, *b);
		calculate_costs(*a, *b);
		find_best_node(*b, &best_node);
		if (!best_node)
			free_and_exit(data, NULL, 1);
		move_to_a_double(b, a, best_node, data);
	}
	//Rotamos en caso sea necesario
	final_rot(a, data);
}

