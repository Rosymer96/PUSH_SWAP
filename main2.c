/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/06 18:39:08 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->size = 0;
	data->strategy = 0;
	data->bench_mode = 0;
	data->disorder = 0;
	data->lis_array = NULL;
	data->lis_size = 0;
	data->count_only = 0;
	data->stats.sa = 0;
	data->stats.sb = 0;
	data->stats.ss = 0;
	data->stats.pa = 0;
	data->stats.pb = 0;
	data->stats.ra = 0;
	data->stats.rb = 0;
	data->stats.rr = 0;
	data->stats.rra = 0;
	data->stats.rrb = 0;
	data->stats.rrr = 0;
	data->stats.total = 0;
}

static void	parse_and_process(t_data *data, char **av)
{
	char	**nums_split;
	int		i;

	i = 1;
	while (av[i])
	{
		if (is_flag(av[i]))
			update_flag(data, av[i]);
		else
		{
			nums_split = ft_split(av[i], ' ');
			if (!nums_split)
				free_and_exit(data, NULL, 1);
			if (!process_num(nums_split, data))
				free_and_exit(data, nums_split, 1);
			free_split(nums_split);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	init_data(&data);
	parse_and_process(&data, av);
	if (data.strategy == 0)
		data.strategy = 1;
	if (data.size == 0)
		free_and_exit(&data, NULL, 0);
	if (check_duplicates(data.stack_a, data.size))
		free_and_exit(&data, NULL, 1);
	data.disorder = get_disorder(data.stack_a, data.size);
	choose_algorithm(&data);
	if (data.bench_mode)
		print_benchmark(&data);
	if (data.count_only == 1)
		ft_putnbr_fd(data.stats.total, 1);
	free_and_exit(&data, NULL, 0);
	return (0);
}
