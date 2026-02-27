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

static void complete_lis_table(int *stack_a, int size, int *lengths, int *prev_pos)
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

static int	find_max_idx(int *lengths, int size)
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

static int	*reconst_lis(int *stack_a, int *prev_pos, int max_idx, int lis_size)
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
		free(lengths);
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
	if (!res)
		return (NULL);
	return (res);
}
