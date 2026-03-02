/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/25 13:46:18 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
            i++;
        else if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
            i++;
        else
            return (0);
	}
	return (1);
}

long long	ft_atoll(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	check_duplicates(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	add_to_stack(t_data *data, int val)
{
	int	*new_s;
	int	i;

	i = 0;
	new_s = malloc(sizeof(int) * (data->size + 1));
	if (!new_s)
		return (0);
	while (i < data->size)
	{
		new_s[i] = data->stack_a[i];
		i++;
	}
	new_s[data->size] = val;
	free(data->stack_a);
	data->stack_a = new_s;
	data->size++;
	return (1);
}
