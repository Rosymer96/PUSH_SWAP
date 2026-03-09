/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:26:23 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:32:53 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_numeric(char *str)
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

static long long	ft_atoll(char *str)
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

static int	add_to_stack(t_data *data, int val)
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

int	process_num(char **nbr, t_data *data)
{
	int			i;
	long long	val;

	i = 0;
	while (nbr[i])
	{
		if (!is_numeric(nbr[i]))
			return (0);
		val = ft_atoll(nbr[i]);
		if (val > 2147483647 || val < -2147483648)
			return (0);
		if (!add_to_stack(data, (int)val))
			return (0);
		i++;
	}
	return (1);
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
