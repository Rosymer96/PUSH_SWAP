/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/25 13:54:38 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void complete_lis_table(int *stack_a, int size, int *lengths, int *prev_pos)
{
	int	i;
	int	j;
	i = 0;
	while (i < size)
	{
		lengths[i] = 1;
		prev_pos[i] = -1;
		i++;
	}
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (stack_a[i] > stack_a[j])
			{
				if (lengths[i] <= lengths[j])
				{
					lengths[i] = lengths[j] + 1;
					prev_pos[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

int	find_max_idx(int *lengths, int size)
{
	int	i;
	int	max_idx;

	max_idx = 0;
	i = 1;
	while (i < size)
	{
		if (lengths[i] > lengths[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	*reconst_lis(int *stack_a, int *prev_pos, int max_idx, int lis_size)
{
	int *res;
	int	i;

	res = malloc(sizeof(int) * lis_size);
	if (!res)
		return (NULL);
	i = lis_size - 1;
	while (max_idx != -1)
	{
		res[i] = stack_a[max_idx];
		max_idx = prev_pos[max_idx];
		i--;
	}
	return (res);
}

int *get_lis_ind(t_data *data, int *lis_size)
{
	int	*lengths;
	int	*prev_pos;
	int	max_idx;
	int *res;

	lengths = malloc(sizeof(int) * data->size);
	if (!lengths)
		return (NULL);
	prev_pos = malloc(sizeof(int) * data->size);
	if (!prev_pos)
	{
		free(lengths); //¿Aqui deberia liberar numero a numero?
		return (NULL);
	}
	//Llamamos a la funcion para llenar la tabla de indices;
	complete_lis_table(data->stack_a, data->size, lengths, prev_pos);
	//encontramos el indice maximo
	max_idx = find_max_idx(lengths, data->size);
	*lis_size = lengths[max_idx];
	//Reconstruimos la secuencia final con los indices:
	res = reconst_lis(data->stack_a, prev_pos, max_idx, *lis_size);
	free(lengths);
	free(prev_pos);

	return (res);
}

void mark_index_lis(t_stack *a, int *lis_array, int lis_size)
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

void push_non_lis(t_stack **a, t_stack **b, t_data data)
{
	int	i;
	int	size;

	i = 0;
	size = data->size;
	while (i < size)
	{
		if ((*a)->index != -1)
			pb(a, b, data);
		else
			ra(a, data);
		i++;
	}
}

int find_min_pos(t_stack *a)
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

int	find_pos_target(t_stack *a, int num_b)
{
	t_stack	*tmp;
	long	num_b_next;
	int num_b_next_pos;
	int 	i;

	tmp = a;
	num_b_next = 2147483648LL
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

int get_len_a(t_stack *a)
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



void	alg_simple(t_data *data, t_stack **a, t_stack **b)
{
	(void)a;
	printf("simple");
}
