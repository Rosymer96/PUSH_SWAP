/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/25 13:54:38 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	find_pos_target(t_stack *a, int num_b)
{
	t_stack	*tmp;
	long	num_b_next;
	int num_b_next_pos;
	int 	i;

	tmp = a;
	num_b_next = 2147483648LL;
	num_b_next_pos = 0;
	i = 0;
	while (tmp)
	{
		if ((tmp->number > num_b) && (a->number < num_b_next))
		{
			num_b_next = tmp->number;
			num_b_next_pos = i;

		}
		i++;
		tmp = tmp->next;
	}
	// si no cambia es porque es el mas grande
	if (num_b_next == 2147483648LL)
		return (find_min_pos(a));
	return (num_b_next_pos);
}

static int get_len_a(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	back_to_a(t_stack **a, t_stack **b, t_data *data)
{
	int	num_b;
	int pos_target;
	int len_a;
	int rra_n;

	if (!a || !*a)
		return ;
	while (*b)
	{
		num_b = (*b)->number;
		pos_target = find_pos_target(*a, num_b);
		len_a = get_len_a(*a);
		if (pos_target <= (len_a / 2))
		{
			while (pos_target > 0)
			{
				ra(a, data);
				pos_target--;
			}
		}
		else
		{
			rra_n = len_a - pos_target;
			while (rra_n > 0)
			{
				rra(a, data);
				rra_n--;
			}
		}
		pa(a, b, data);
	}
}

static int find_min_pos(t_stack *a)
{
	int min_val;
	int min_pos;
	int i;

	min_val = a->number;
	min_pos = 0;
	i = 0;
	while (a)
	{
		if (a->number < min_val)
		{
			min_val = a->number;
			min_pos = i;
		}
		a = a->next;
		i++;
	}
	return (min_pos);

}

void final_rot(t_stack **a, t_data *data)
{
	int pos_min;
	int len_a;
	int total_rra;

	if (!a || !*a)
		return ;
	pos_min = find_min_pos(*a);
	len_a = get_len_a(*a);
	if (pos_min <= len_a /2)
	{
		while (pos_min > 0)
		{
			ra(a, data);
			pos_min--;
		}
	}
	else
	{
		total_rra = len_a - pos_min;
		while (total_rra > 0)
		{
			rra(a, data);
			total_rra--;
		}
	}
}
