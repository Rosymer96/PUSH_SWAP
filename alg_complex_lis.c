/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple_lis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:35 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/25 13:54:38 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void complete_lis_table(int *stack_a, int size, int *lengths, int *prev_pos)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		lengths[i] = 1;
		prev_pos[i] = -1;
	}
	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if ((stack_a[i] > stack_a[j]) && (lengths[i] <= lengths[j]))
			{
				lengths[i] = lengths[j] + 1;
				prev_pos[i] = j;
			}
		}
	}
}

static int	find_max_len(int *lengths, int size)
{
	int	i;
	int	max_len;

	max_len = 0;
	i = 1;
	while (i < size)
	{
		if (lengths[i] > lengths[max_len])
			max_len = i;
		i++;
	}
	return (max_len);
}

static int	*reconst_lis(int *stack_a, int *prev_pos, int max_len, int lis_size)
{
	int *res;
	int	i;

	res = malloc(sizeof(int) * lis_size);
	if (!res)
		return (NULL);
	i = lis_size - 1;
	while (max_len != -1)
	{
		res[i] = stack_a[max_len];
		max_len = prev_pos[max_len];
		i--;
	}
	return (res);
}

int *get_lis_ind(t_data *data)
{
	int	*lengths;
	int	*prev_pos;
	int	max_len;
	int *res;

	lengths = malloc(sizeof(int) * data->size);
	if (!lengths)
		return (NULL);
	prev_pos = malloc(sizeof(int) * data->size);
	if (!prev_pos)
	{
		free(lengths);
		return (NULL);
	}
	complete_lis_table(data->stack_a, data->size, lengths, prev_pos);
	max_len = find_max_len(lengths, data->size);
	data->lis_size = lengths[max_len];
	res = reconst_lis(data->stack_a, prev_pos, max_len, data->lis_size);
	free(lengths);
	free(prev_pos);
	if (!res)
		return (NULL);
	return (res);
}

int	is_in_lis(int number, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lis_size)
	{
		if (data->lis_array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

