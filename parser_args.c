/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:15:45 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/04 14:40:35 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-' && arg[2] != '\0')
		return (1);
	return (0);
}

void	update_flag(t_data *data, char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		if (data->strategy != 0)
			free_and_exit(data, NULL, 1);
		data->strategy = 2; // O(n2) LIS
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		if (data->strategy != 0)
			free_and_exit(data, NULL, 1);
		data->strategy = 3; // O(n*sqrt(n)) K-sort
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		if (data->strategy != 0)
			free_and_exit(data, NULL, 1);
		data->strategy = 4; // O(n log n) Radix
	}
	else if (ft_strncmp(arg, "--adaptive", 9) == 0)
	{
		if (data->strategy != 0)
			free_and_exit(data, NULL, 1);
		data->strategy = 1;
	}
	else if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (data->bench_mode != 0)
			free_and_exit(data, NULL, 1);
		data->bench_mode = 1; // Activa modo benchmark
	}
	else
		free_and_exit(data, NULL, 1); // Es potencialmente un número
}

int	process_num(char **nums_split, t_data *data)
{
	int			i;
	long long	val;

	i = 0;
	while (nums_split[i])
	{
		if (!is_numeric(nums_split[i]))
			return (0);
		val = ft_atoll(nums_split[i]);
		if (val > 2147483647 || val < -2147483648)
			return (0);
		if (!add_to_stack(data, (int)val))
			return (0);
		i++;
	}
	return (1);
}
